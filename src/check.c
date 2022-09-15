/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:32:24 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/15 09:58:51 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_move1(t_move *ref, t_move *move1)
{
	init_move(move1, ref->index_a, ref->index_b, 1);
	move1->ra = ref->ra;
	move1->rrb = ref->rrb;
	move1->total = move1->ra + move1->rrb;
}

static void	get_move2(t_move *ref, t_move *move2)
{
	init_move(move2, ref->index_a, ref->index_b, 2);
	move2->rb = ref->rb;
	move2->rra = ref->rra;
	move2->total = move2->rb + move2->rra;
}

static void	get_move3(t_move *ref, t_move *move3)
{
	init_move(move3, ref->index_a, ref->index_b, 3);
	move3->rr = ft_min(ref->ra, ref->rb);
	move3->ra = ref->ra - move3->rr;
	move3->rb = ref->rb - move3->rr;
	move3->total = move3->ra + move3->rb + move3->rr;
}

static void	get_move4(t_move *ref, t_move *move4)
{
	init_move(move4, ref->index_a, ref->index_b, 4);
	move4->rrr = ft_min(ref->rra, ref->rrb);
	move4->rra = ref->rra - move4->rrr;
	move4->rrb = ref->rrb - move4->rrr;
	move4->total = move4->rra + move4->rrb + move4->rrr;
}

t_move	*check_move(t_sort *sort, int index_a, int index_b)
{
	t_move	ref;
	t_move	move1;
	t_move	move2;
	t_move	move3;
	t_move	move4;

	ref.index_a = ft_max(index_a, 1);
	ref.index_b = ft_max(index_b, 1);
	ref.ra = ref.index_a - 1;
	ref.rb = ref.index_b - 1;
	ref.rra = sort->stack_a.size - ref.index_a + 1;
	ref.rrb = sort->stack_b.size - ref.index_b + 1;
	get_move1(&ref, &move1);
	get_move2(&ref, &move2);
	get_move3(&ref, &move3);
	get_move4(&ref, &move4);
	if (move1.total <= ft_min(move2.total, move3.total)
		&& move1.total <= move4.total)
		return (clone_move(&move1));
	else if (move2.total <= ft_min(move3.total, move4.total))
		return (clone_move(&move2));
	else if (move3.total <= move4.total)
		return (clone_move(&move3));
	else
		return (clone_move(&move4));
}
