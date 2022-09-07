/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:05:43 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/07 10:47:52 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pulling_to_b(t_sorting *sorting, t_stack *stack_a, t_stack *stack_b)
{
	while (stack_not_sorted(stack_a, stack_b) && stack_size(stack_a) > 2)
	{
		set_sorting_information(sorting, stack_a);
		while (stack_not_sorted(stack_a, stack_b)
			&& pivot_separated_stack(stack_a, sorting->center_pivot))
		{
			if (best_pulling_move(stack_a, sorting->center_pivot) == 1)
				while (stack_a->top
					&& stack_a->top->data > sorting->center_pivot)
					psl(stack_a, stack_b, "ra");
			else
				while (stack_a->top
					&& stack_a->top->data > sorting->center_pivot)
					psl(stack_a, stack_b, "rra");
			if (stack_a->top && stack_a->top->data <= sorting->center_pivot)
				psl(stack_a, stack_b, "pb");
			if (stack_b->top && stack_b->top->next)
			{
				if (stack_b->top->data
					< ((t_element *)(stack_b->top->next))->data)
					psl(stack_a, stack_b, "sb");
			}
		}
		free(sorting->tmp_values);
	}
}

void	pulling_to_a(t_sorting *sorting, t_stack *stack_a, t_stack *stack_b)
{
	int	nbr;

	if (stack_a->top && stack_a->top->next)
		if (stack_a->top->data > ((t_element *)(stack_a->top->next))->data)
			psl(stack_a, stack_b, "sa");
	while (stack_not_sorted(stack_a, stack_b) && stack_size(stack_b) > 0)
	{
		nbr = next_element(sorting, stack_a);
		if (best_top_move(stack_b, nbr) == 1)
			while (stack_not_sorted(stack_a, stack_b)
				&& stack_b->top->data != nbr)
				psl(stack_a, stack_b, "rb");
		else
			while (stack_not_sorted(stack_a, stack_b)
				&& stack_b->top->data != nbr)
				psl(stack_a, stack_b, "rrb");
		psl(stack_a, stack_b, "pa");
	}
}

void	sort_stacks(t_sorting *sorting, t_stack *stack_a, t_stack *stack_b)
{
	pulling_to_b(sorting, stack_a, stack_b);
	pulling_to_a(sorting, stack_a, stack_b);
}
