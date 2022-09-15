/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:05:43 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/15 10:00:56 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stacks(t_sort *sort, t_move	*move)
{
	int		i;

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

	while (stack_not_sorted(sort) && sort->stack_a.size > 2)
	{
		if (run_ss(sort))
			psl(sort, "ss");
		pivot = get_center_pivot(&sort->stack_a, 4);
		move = movement_a_to_b(sort, pivot);
		rotate_stacks(sort, move);
		psl(sort, "pb");
		free(move);
	}
}

static void	pulling_to_a(t_sort *sort)
{
	t_move	*move;

	while (sort->stack_b.size > 0)
	{
		move = movement_b_to_a(sort);
		rotate_stacks(sort, move);
		psl(sort, "pa");
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
	move2 = sort->stack_a.size - index;
	if (move1 <= move2)
		move.ra = move1;
	else
		move.rra = move2;
	rotate_stacks(sort, &move);
}

void	sort_stacks(t_sort *sort)
{
	pulling_to_b(sort);
	pulling_to_a(sort);
	pulling_to_top_a(sort, sort->min);
}
