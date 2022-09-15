/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:22:13 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/15 10:22:07 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_stack(t_stack *stack)
{
	t_element	*node;

	stack->size = 0;
	node = stack->top;
	while (node && node->next && node->next != stack->top)
	{
		node = node->next;
		++stack->size;
	}
	if (node)
	{
		node->next = NULL;
		++stack->size;
	}
}

int	stack_not_sorted(t_sort *sort)
{
	t_element	*element;
	int			value;

	if (sort->stack_b.top != NULL)
		return (1);
	element = sort->stack_a.top;
	if (element)
		value = element->data;
	while (element)
	{
		if (element && element != sort->stack_a.top && element->data < value)
			return (1);
		if (element)
			value = element->data;
		element = element->next;
	}
	return (0);
}

int	stack_value(t_stack *stack, int position)
{
	t_element	*element;
	int			i;
	int			value;

	if (position <= 0)
		position = stack->size;
	--position;
	value = 0;
	i = 0;
	element = stack->top;
	while (element && i != position)
	{
		element = element->next;
		++i;
	}
	if (element)
		value = element->data;
	return (value);
}

int	stack_index(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (++i <= stack->size)
		if (stack_value(stack, i) == value)
			return (i);
	return (0);
}
