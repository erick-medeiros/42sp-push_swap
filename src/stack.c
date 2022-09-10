/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:22:13 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/10 14:59:48 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

void	create_stack(t_stack *stack, int argc, char *argv[])
{
	t_element	*current;
	t_element	*last;
	int			i;

	i = argc - 1;
	last = NULL;
	while (i >= 1)
	{
		current = malloc(sizeof(t_element));
		if (current == NULL)
			return ;
		current->next = last;
		current->data = ft_atoi(argv[i]);
		last = current;
		--i;
	}
	stack->top = last;
}

void	update_bottom_stack(t_stack *stack)
{
	t_element	*bot;

	bot = stack->top;
	while (bot && bot->next && bot->next != stack->top)
		bot = bot->next;
	if (bot)
		bot->next = NULL;
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

	--position;
	if (position < 0)
		position = 0;
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
