/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:05:43 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/06 14:41:13 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_sorting *sorting, t_stack *stack_a, t_stack *stack_b)
{
	t_element	*element;
	int			i;

	element = stack_a->top;
	i = 0;
	while (i < sorting->list_size && stack_not_sorted(stack_a, stack_b))
	{
		if (element && element->data <= sorting->center_pivot)
			psl(stack_a, stack_b, "pb");
		else
			psl(stack_a, stack_b, "ra");
		element = stack_a->top;
		++i;
	}
}

int	stack_not_sorted(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*element;
	int			value;

	if (stack_b->top != NULL)
		return (1);
	element = stack_a->top;
	if (element)
		value = element->data;
	while (element)
	{
		if (element && element != stack_a->top && element->data < value)
			return (1);
		if (element)
			value = element->data;
		element = element->next;
	}
	return (0);
}
