/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:01:45 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/16 10:17:29 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	best_value_ab(t_sort *sort, int index_b)
{
	int	i;
	int	value_b;
	int	value_a;
	int	index_a;
	int	value_i;

	value_b = stack_value(sort->stack_b, index_b);
	i = 0;
	index_a = 0;
	while (++i <= sort->stack_a->size)
	{
		value_a = stack_value(sort->stack_a, index_a);
		value_i = stack_value(sort->stack_a, i);
		if (index_a == 0 && value_i > value_b)
			index_a = i;
		else if (value_i > value_b && value_i < value_a)
			index_a = i;
	}
	return (index_a);
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
