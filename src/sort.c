/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:05:43 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/12 19:50:34 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static	int	keep_pulling(t_stack *stack_a, t_stack *stack_b, char c, int size)
{
	if (c == 'a')
		return (stack_not_sorted(stack_a, stack_b)
			&& stack_size(stack_a) > size);
	else
		return (stack_not_sorted(stack_a, stack_b)
			&& stack_size(stack_b) > size);
}

static void	double_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_size(stack_a) >= 2 && stack_size(stack_b) >= 2
		&& stack_value(stack_a, 1) > stack_value(stack_a, 2)
		&& stack_value(stack_b, 1) < stack_value(stack_b, 2))
		psl(stack_a, stack_b, "ss");
	if (stack_value(stack_b, 1) < stack_value(stack_b, 2))
		psl(stack_a, stack_b, "sb");
}

void	pulling_to_b(t_sorting *sorting, t_stack *stack_a, t_stack *stack_b)
{
	while (keep_pulling(stack_a, stack_b, 'a', 2))
	{
		set_sorting_information(sorting, stack_a);
		while (keep_pulling(stack_a, stack_b, 'a', 2)
			&& pivot_separated_stack(stack_a, sorting->center_pivot))
		{
			if (stack_value(stack_a, 1) <= sorting->center_pivot)
			{
				psl(stack_a, stack_b, "pb");
				double_swap(stack_a, stack_b);
			}
			else if (best_pulling_move(stack_a, sorting->center_pivot) == 1)
				while (stack_value(stack_a, 1) > sorting->center_pivot)
					psl(stack_a, stack_b, "ra");
			else
				while (stack_value(stack_a, 1) > sorting->center_pivot)
					psl(stack_a, stack_b, "rra");
		}
		free(sorting->tmp_values);
	}
	if (stack_size(stack_a) >= 2)
		if (stack_value(stack_a, 1) > stack_value(stack_a, 2))
			psl(stack_a, stack_b, "sa");
}

int		best_pulling_to_a(t_stack *stack_a, t_stack *stack_b);
void	exec_rotate(t_stack *stack_a, t_stack *stack_b);
void	exec_rotate_run(t_stack *stack_a, t_stack *stack_b, int value);

void	pulling_to_a(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_size(stack_b) > 0)
	{
		if (best_pulling_to_a(stack_a, stack_b) == 0)
			psl(stack_a, stack_b, "pa");
		else
		{
			if (best_pulling_to_a(stack_a, stack_b) == 1)
				psl(stack_a, stack_b, "sb");
			if (best_pulling_to_a(stack_a, stack_b) == 2)
				psl(stack_a, stack_b, "rb");
			if (best_pulling_to_a(stack_a, stack_b) == 3)
				psl(stack_a, stack_b, "rrb");
			exec_rotate(stack_a, stack_b);
		}
	}
}

void	align_stack_a(t_sorting *sorting, t_stack *stack_a, t_stack *stack_b)
{
	exec_rotate_run(
		stack_a, stack_b,
		sorting->values[sorting->list_size - 1]);
}

void	sort_stacks(t_sorting *sorting, t_stack *stack_a, t_stack *stack_b)
{
	pulling_to_b(sorting, stack_a, stack_b);
	pulling_to_a(stack_a, stack_b);
	align_stack_a(sorting, stack_a, stack_b);
}
