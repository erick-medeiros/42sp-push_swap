/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:30:30 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/16 14:12:23 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	run_ss(t_sort *sort)
{
	if (sort->stack_a->size >= 3 && sort->stack_b->size >= 3
		&& stack_value(sort->stack_a, 1) > stack_value(sort->stack_a, 2)
		&& stack_value(sort->stack_b, 1) < stack_value(sort->stack_b, 2))
		return (TRUE);
	return (FALSE);
}

int	run_sa(t_sort *sort)
{
	int	first;
	int	second;
	int	last;

	first = stack_value(sort->stack_a, 1);
	second = stack_value(sort->stack_a, 2);
	last = stack_value(sort->stack_a, sort->stack_a->size);
	return (sort->stack_a->size > 2 && sort->stack_a->size < 5
		&& last < first && last < second && first > second
	);
}

int	run_sa_last(t_sort	*sort)
{
	int	first;
	int	penultimate;
	int	last;

	first = stack_value(sort->stack_a, 1);
	last = stack_value(sort->stack_a, sort->stack_a->size);
	penultimate = stack_value(sort->stack_a, sort->stack_a->size - 1);
	return (sort->stack_a->size > 2 && sort->stack_a->size < 5
		&& last < first && penultimate < first && penultimate > last
	);
}

int	run_sb_last(t_sort *sort)
{
	int	first;
	int	penultimate;
	int	last;
	int	top_a;
	int	bot_a;

	top_a = stack_value(sort->stack_a, 1);
	bot_a = stack_value(sort->stack_a, sort->stack_a->size);
	first = stack_value(sort->stack_b, 1);
	last = stack_value(sort->stack_b, sort->stack_b->size);
	penultimate = stack_value(sort->stack_b, sort->stack_b->size - 1);
	return (sort->stack_b->size > 2 && sort->stack_b->size < 5
		&& last > first && penultimate > first && penultimate < last
		&& last < top_a && penultimate < top_a && first < top_a
		&& last > bot_a && penultimate > bot_a && first > bot_a
	);
}

void	swap_stack(t_sort *sort, char *instruction)
{
	if (!ft_strcmp(instruction, "sa"))
	{
		if (run_ss(sort))
			psl(sort, "ss");
		else
			psl(sort, "sa");
	}
	else if (!ft_strcmp(instruction, "sb"))
	{
		if (run_ss(sort))
			psl(sort, "ss");
		else
			psl(sort, "sb");
	}
}
