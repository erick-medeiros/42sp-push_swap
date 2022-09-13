/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:22:13 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/13 00:30:49 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_bottom_stack(t_stack *stack)
{
	t_element	*bot;

	bot = stack->top;
	while (bot && bot->next && bot->next != stack->top)
		bot = bot->next;
	if (bot)
		bot->next = NULL;
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

int	stack_size(t_stack *stack)
{
	t_element	*element;
	int			size;

	size = 0;
	element = stack->top;
	while (element)
	{
		element = element->next;
		++size;
	}
	return (size);
}

int	stack_value(t_stack *stack, int position)
{
	t_element	*element;
	int			i;
	int			value;

	if (position <= 0)
		position = stack_size(stack);
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
	int	len;
	int	i;

	len = stack_size(stack);
	i = 0;
	if (len == 0)
		return (i);
	while (++i <= len)
		if (stack_value(stack, i) == value)
			return (i);
	return (0);
}
