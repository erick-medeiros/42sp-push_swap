/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:22:13 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/16 14:26:28 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_stack(t_stack *stack)
{
	t_node	*node;

	stack->size = 0;
	stack->min = 0;
	stack->max = 0;
	node = stack->top;
	while (node)
	{
		if (node == stack->top)
		{
			stack->min = node->data;
			stack->max = node->data;
		}
		else
		{
			stack->min = ft_min(stack->min, node->data);
			stack->max = ft_max(stack->max, node->data);
		}
		++stack->size;
		if (node->next == stack->top)
			node->next = NULL;
		node = node->next;
	}
}

int	stack_is_unsorted(t_stack *stack)
{
	t_node	*node;
	int		previous;
	int		link_max_min;

	if (stack->size == 0)
		return (FALSE);
	previous = stack_value(stack, 1);
	node = stack->top;
	link_max_min = FALSE;
	while (node)
	{
		if (previous == stack->max && node->data == stack->min)
			link_max_min = TRUE;
		if (link_max_min)
			if (node != stack->top && node->data > stack->top->data)
				return (TRUE);
		if (node != stack->top && node->data < previous)
			if (previous != stack->max || node->data != stack->min)
				return (TRUE);
		previous = node->data;
		node = node->next;
	}
	return (FALSE);
}

int	stack_value(t_stack *stack, int position)
{
	t_node	*node;
	int		i;
	int		value;

	if (position <= 0)
		position = stack->size;
	--position;
	value = 0;
	i = 0;
	node = stack->top;
	while (node && i != position)
	{
		node = node->next;
		++i;
	}
	if (node)
		value = node->data;
	return (value);
}
