/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:30:30 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/17 19:42:02 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_swap
{
	int	first;
	int	second;
	int	penult;
	int	last;
}	t_swap;

static void	swap_stack(t_sort *sort, char *instruction)
{
	if (sort->stack_a->size >= 3 && sort->stack_b->size >= 3
		&& stack_value(sort->stack_a, 1) > stack_value(sort->stack_a, 2)
		&& stack_value(sort->stack_b, 1) < stack_value(sort->stack_b, 2))
		psl(sort, "ss");
	if (!ft_strcmp(instruction, "sa"))
	{
		if (stack_value(sort->stack_a, 1) > stack_value(sort->stack_a, 2))
			psl(sort, "sa");
	}
	else if (!ft_strcmp(instruction, "sb"))
	{
		if (stack_value(sort->stack_b, 2) > stack_value(sort->stack_b, 1))
			psl(sort, "sb");
	}
}

void	swap_a(t_sort *sort)
{
	t_swap	s;

	s.first = stack_value(sort->stack_a, 1);
	s.second = stack_value(sort->stack_a, 2);
	s.penult = stack_value(sort->stack_a, sort->stack_a->size - 1);
	s.last = stack_value(sort->stack_a, sort->stack_a->size);
	swap_stack(sort, "ss");
	if (sort->stack_a->size == 3)
	{
		swap_stack(sort, "sa");
		if (s.last > s.first && s.last < s.second)
			psl(sort, "rra");
		swap_stack(sort, "sa");
	}
	else if (sort->stack_a->size == 4)
	{
		if (s.second > s.penult && s.second > s.last)
			swap_stack(sort, "sa");
		if (s.first > s.penult && s.first > s.last && s.penult > s.last)
		{
			psl(sort, "rra");
			psl(sort, "rra");
		}
		swap_stack(sort, "sa");
	}
}

void	swap_b(t_sort *sort)
{
	int	first;
	int	penultimate;
	int	last;
	int	top_a;
	int	bot_a;

	if (sort->stack_b->size == 4)
	{
		top_a = stack_value(sort->stack_a, 1);
		bot_a = stack_value(sort->stack_a, sort->stack_a->size);
		first = stack_value(sort->stack_b, 1);
		last = stack_value(sort->stack_b, sort->stack_b->size);
		penultimate = stack_value(sort->stack_b, sort->stack_b->size - 1);
		if (last > first && penultimate > first && penultimate < last
			&& last < top_a && penultimate < top_a && first < top_a
			&& last > bot_a && penultimate > bot_a && first > bot_a
		)
		{
			psl(sort, "rrb");
			psl(sort, "rrb");
			swap_stack(sort, "sb");
		}
	}
}
