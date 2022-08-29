/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:22:13 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/29 13:12:33 by eandre-f         ###   ########.fr       */
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

void	get_values_from_stack(t_sorting *sorting, t_stack *stack)
{
	t_element	*element;
	size_t		len;

	sorting->values = NULL;
	len = 0;
	element = stack->top;
	while (element && ++len)
		element = element->next;
	sorting->list_size = len;
	if (len == 0)
		return ;
	sorting->values = malloc(sizeof(int) * len);
	if (sorting->values != NULL)
	{
		len = 0;
		element = stack->top;
		while (element)
		{
			sorting->values[len] = element->data;
			element = element->next;
			++len;
		}
	}
}
