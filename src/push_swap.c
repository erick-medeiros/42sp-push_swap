/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:22:13 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/23 20:11:28 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

void	define_next(t_stack *stack, int size);

void	create_stack(t_stack *stack, int argc, char *argv[])
{
	t_layer	*layer;
	t_layer	*prev;
	int		i;

	i = 0;
	while (i < argc - 1)
	{
		layer = malloc(sizeof(t_layer));
		if (layer == NULL)
			return ;
		layer->prev = NULL;
		layer->next = NULL;
		if (i == 0)
			stack->start = layer;
		else
			layer->prev = prev;
		layer->value = ft_atoi(argv[i + 1]);
		prev = layer;
		++i;
	}
	stack->start->prev = prev;
	define_next(stack, argc - 1);
}

void	define_next(t_stack *stack, int size)
{
	t_layer	*layer;
	t_layer	*prev;
	int		i;

	i = size - 1;
	while (i >= 0)
	{
		if (i == size - 1)
			layer = stack->start;
		prev = layer->prev;
		prev->next = layer;
		layer = layer->prev;
		--i;
	}
}