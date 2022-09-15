/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:32:24 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/15 19:19:17 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_move_ra_rrb(t_move *ref, t_move *move, int id)
{
	init_move(move, ref->index_a, ref->index_b, id);
	move->ra = ref->ra;
	move->rrb = ref->rrb;
	move->total = move->ra + move->rrb;
}

static void	get_move_rra_rb(t_move *ref, t_move *move, int id)
{
	init_move(move, ref->index_a, ref->index_b, id);
	move->rb = ref->rb;
	move->rra = ref->rra;
	move->total = move->rb + move->rra;
}

static void	get_move_ra_rb(t_move *ref, t_move *move, int id)
{
	init_move(move, ref->index_a, ref->index_b, id);
	move->rr = ft_min(ref->ra, ref->rb);
	move->ra = ref->ra - move->rr;
	move->rb = ref->rb - move->rr;
	move->total = move->ra + move->rb + move->rr;
}

static void	get_move_rra_rrb(t_move *ref, t_move *move, int id)
{
	init_move(move, ref->index_a, ref->index_b, id);
	move->rrr = ft_min(ref->rra, ref->rrb);
	move->rra = ref->rra - move->rrr;
	move->rrb = ref->rrb - move->rrr;
	move->total = move->rra + move->rrb + move->rrr;
}

t_move	*check_move(t_sort *sort, int index_a, int index_b)
{
	t_move	ref;
	t_move	m1;
	t_move	m2;
	t_move	m3;
	t_move	m4;

	init_move(&ref, ft_max(index_a, 1), ft_max(index_b, 1), 0);
	ref.ra = ref.index_a - 1;
	ref.rb = ref.index_b - 1;
	if (sort->stack_a.size > 1)
		ref.rra = sort->stack_a.size - ref.index_a + 1;
	if (sort->stack_b.size > 1)
		ref.rrb = sort->stack_b.size - ref.index_b + 1;
	get_move_ra_rb(&ref, &m1, 1);
	get_move_rra_rrb(&ref, &m2, 2);
	get_move_ra_rrb(&ref, &m3, 3);
	get_move_rra_rb(&ref, &m4, 4);
	if (m1.total <= m2.total && m1.total <= m3.total && m1.total <= m4.total)
		return (clone_move(&m1));
	else if (m2.total <= m3.total && m2.total <= m4.total)
		return (clone_move(&m2));
	else if (m3.total <= m4.total)
		return (clone_move(&m3));
	else
		return (clone_move(&m4));
}
