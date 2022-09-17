/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:01:45 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/17 12:57:07 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_rotation
{
	t_move	ra_rb;
	t_move	rra_rrb;
	t_move	ra_rrb;
	t_move	rra_rb;
}	t_rotation;

static void	set_rotation(t_rotation *rotation, t_move *info)
{
	init_move(&rotation->ra_rb, info->index_a, info->index_b);
	rotation->ra_rb.rr = ft_min(info->ra, info->rb);
	rotation->ra_rb.ra = info->ra - rotation->ra_rb.rr;
	rotation->ra_rb.rb = info->rb - rotation->ra_rb.rr;
	rotation->ra_rb.total = rotation->ra_rb.ra
		+ rotation->ra_rb.rb + rotation->ra_rb.rr;
	init_move(&rotation->rra_rrb, info->index_a, info->index_b);
	rotation->rra_rrb.rrr = ft_min(info->rra, info->rrb);
	rotation->rra_rrb.rra = info->rra - rotation->rra_rrb.rrr;
	rotation->rra_rrb.rrb = info->rrb - rotation->rra_rrb.rrr;
	rotation->rra_rrb.total = rotation->rra_rrb.rra
		+ rotation->rra_rrb.rrb + rotation->rra_rrb.rrr;
	init_move(&rotation->ra_rrb, info->index_a, info->index_b);
	rotation->ra_rrb.ra = info->ra;
	rotation->ra_rrb.rrb = info->rrb;
	rotation->ra_rrb.total = rotation->ra_rrb.ra + rotation->ra_rrb.rrb;
	init_move(&rotation->rra_rb, info->index_a, info->index_b);
	rotation->rra_rb.rb = info->rb;
	rotation->rra_rb.rra = info->rra;
	rotation->rra_rb.total = rotation->rra_rb.rb + rotation->rra_rb.rra;
}

static t_move	*check_move(t_sort *sort, int index_a, int index_b)
{
	t_rotation	rotation;
	t_move		info;

	init_move(&info, ft_max(index_a, 1), ft_max(index_b, 1));
	info.ra = info.index_a - 1;
	info.rb = info.index_b - 1;
	if (sort->stack_a->size > 1)
		info.rra = sort->stack_a->size - info.index_a + 1;
	if (sort->stack_b->size > 1)
		info.rrb = sort->stack_b->size - info.index_b + 1;
	set_rotation(&rotation, &info);
	if (rotation.ra_rb.total <= rotation.rra_rrb.total
		&& rotation.ra_rb.total <= rotation.ra_rrb.total
		&& rotation.ra_rb.total <= rotation.rra_rb.total)
		return (clone_move(&rotation.ra_rb));
	else if (rotation.rra_rrb.total <= rotation.ra_rrb.total
		&& rotation.rra_rrb.total <= rotation.rra_rb.total)
		return (clone_move(&rotation.rra_rrb));
	else if (rotation.ra_rrb.total <= rotation.rra_rb.total)
		return (clone_move(&rotation.ra_rrb));
	else
		return (clone_move(&rotation.rra_rb));
}

static int	best_value_ab(t_sort *sort, int index_b)
{
	t_node	*node;
	int		value_b;
	int		value_a;
	int		index;
	int		i;

	value_b = stack_value(sort->stack_b, index_b);
	i = 0;
	index = 0;
	node = sort->stack_a->top;
	while (node)
	{
		++i;
		if (node->data > value_b && (index == 0 || node->data < value_a))
		{
			index = i;
			value_a = node->data;
		}
		node = node->next;
	}
	return (index);
}

t_move	*movement_a_to_b(t_sort *sort, int pivot)
{
	t_move	*top;
	t_move	*bot;
	int		i_top;
	int		i_bot;
	int		size;

	size = sort->stack_a->size;
	i_top = 1;
	while (i_top <= size && stack_value(sort->stack_a, i_top) > pivot)
		++i_top;
	i_bot = size;
	while (i_bot > 0 && stack_value(sort->stack_a, i_bot) > pivot)
		--i_bot;
	top = check_move(sort, i_top, 1);
	bot = check_move(sort, i_bot, 1);
	if (top && bot && top->total <= bot->total)
	{
		free(bot);
		return (top);
	}
	free(top);
	return (bot);
}

t_move	*movement_b_to_a(t_sort *sort)
{
	t_move	*move;
	t_move	*tmp;
	int		index_b;
	int		index_a;

	index_b = 0;
	move = NULL;
	while (++index_b <= sort->stack_b->size)
	{
		index_a = best_value_ab(sort, index_b);
		tmp = check_move(sort, index_a, index_b);
		if (index_b == 1)
			move = tmp;
		if (tmp && move && tmp->total < move->total)
		{
			free(move);
			move = tmp;
		}
		else if (tmp != move)
			free(tmp);
	}
	return (move);
}
