/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:05:43 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/14 18:31:12 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stacks(t_sort *sort, t_move	*move)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_a = &sort->stack_a;
	stack_b = &sort->stack_b;
	i = 0;
	while (move && ++i <= move->rr)
		psl(stack_a, stack_b, "rr");
	i = 0;
	while (move && ++i <= move->rrr)
		psl(stack_a, stack_b, "rrr");
	i = 0;
	while (move && ++i <= move->ra)
		psl(stack_a, stack_b, "ra");
	i = 0;
	while (move && ++i <= move->rb)
		psl(stack_a, stack_b, "rb");
	i = 0;
	while (move && ++i <= move->rra)
		psl(stack_a, stack_b, "rra");
	i = 0;
	while (move && ++i <= move->rrb)
		psl(stack_a, stack_b, "rrb");
}

static void	pulling_to_b(t_sort *sort, t_stack *stack_a, t_stack *stack_b)
{
	t_move	*move;
	int		pivot;

	while (stack_not_sorted(stack_a, stack_b) && stack_size(stack_a) > 2)
	{
		if (run_ss(sort))
			psl(stack_a, stack_b, "ss");
		pivot = get_center_pivot(stack_a, 4);
		move = movement_a_to_b(sort, pivot);
		rotate_stacks(sort, move);
		psl(stack_a, stack_b, "pb");
		free(move);
	}
}

static void	pulling_to_a(t_sort *sort, t_stack *stack_a, t_stack *stack_b)
{
	t_move	*move;

	while (stack_size(stack_b) > 0)
	{
		move = movement_b_to_a(sort);
		rotate_stacks(sort, move);
		psl(stack_a, stack_b, "pa");
		free(move);
	}
}

static void	pulling_to_top_a(t_sort *sort, int value)
{
	t_move	move;
	int		move1;
	int		move2;
	int		index;

	if (stack_value(&sort->stack_a, 1) == value)
		return ;
	index = stack_index(&sort->stack_a, value) - 1;
	if (index < 0)
		return ;
	init_move(&move, index, -1, 5);
	move1 = index;
	move2 = stack_size(&sort->stack_a) - index;
	if (move1 <= move2)
		move.ra = move1;
	else
		move.rra = move2;
	rotate_stacks(sort, &move);
}

void	sort_stacks(t_sort *sort)
{
	pulling_to_b(sort, &sort->stack_a, &sort->stack_b);
	pulling_to_a(sort, &sort->stack_a, &sort->stack_b);
	pulling_to_top_a(sort, sort->min);
}
