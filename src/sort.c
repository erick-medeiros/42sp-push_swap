/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:05:43 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/17 23:14:42 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stacks(t_sort *sort, t_move *move)
{
	int	i;

	i = 0;
	while (move && ++i <= move->rr)
		psl(sort, "rr");
	i = 0;
	while (move && ++i <= move->rrr)
		psl(sort, "rrr");
	i = 0;
	while (move && ++i <= move->ra)
		psl(sort, "ra");
	i = 0;
	while (move && ++i <= move->rb)
		psl(sort, "rb");
	i = 0;
	while (move && ++i <= move->rra)
		psl(sort, "rra");
	i = 0;
	while (move && ++i <= move->rrb)
		psl(sort, "rrb");
}

static void	pulling_to_b(t_sort *sort)
{
	t_move	*move;
	int		pivot;

	pivot = get_center_pivot(sort->stack_a, 2);
	while (stack_is_unsorted(sort->stack_a) && sort->stack_a->size > 2)
	{
		swap_a(sort);
		if (sort->stack_a->min > pivot)
			pivot = get_center_pivot(sort->stack_a, 2);
		move = movement_a_to_b(sort, pivot);
		rotate_stacks(sort, move);
		if (stack_is_unsorted(sort->stack_a))
			psl(sort, "pb");
		free(move);
	}
}

static void	pulling_to_a(t_sort *sort)
{
	t_move	*move;

	while (sort->stack_b->size > 0)
	{
		move = movement_b_to_a(sort);
		rotate_stacks(sort, move);
		swap_b(sort);
		psl(sort, "pa");
		free(move);
	}
}

static void	pulling_to_top(t_sort *sort, t_stack *stack, int value)
{
	t_move	move;
	int		ra;
	int		rra;
	int		i;

	if (stack_value(stack, 1) == value)
		return ;
	i = 0;
	while (i < stack->size && stack_value(stack, i + 1) != value)
		++i;
	init_move(&move, i, 0);
	ra = i;
	rra = stack->size - i;
	if (ra <= rra)
		move.ra = ra;
	else
		move.rra = rra;
	rotate_stacks(sort, &move);
}

void	sort_stacks(t_sort *sort)
{
	pulling_to_b(sort);
	pulling_to_a(sort);
	pulling_to_top(sort, sort->stack_a, sort->min);
}
