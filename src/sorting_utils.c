/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:47:24 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/12 23:12:06 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pivot_separated_stack(t_stack *stack, int pivot)
{
	t_element	*element;

	element = stack->top;
	while (element)
	{
		if (element->data <= pivot)
			return (1);
		element = element->next;
	}
	return (0);
}

void	best_top_move_a(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	size;
	int	ra_i;
	int	rra_i;
	int	i;

	size = stack_size(stack_a);
	i = 0;
	ra_i = 0;
	while (++i <= size && stack_value(stack_a, i) == value)
		++ra_i;
	i = size + 1;
	rra_i = 0;
	while (--i > 0 && stack_value(stack_a, i) == value)
		++rra_i;
	i = 0;
	if (ra_i <= rra_i)
		while (++i <= ra_i)
			psl(stack_a, stack_b, "ra");
	else
		while (++i <= rra_i)
			psl(stack_a, stack_b, "rra");
}
