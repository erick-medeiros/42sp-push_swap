/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:52:55 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/23 21:12:42 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_layer	*layer;

	layer = stack->start->next;
	while (layer && layer->next != stack->start)
	{
		layer = layer->next;
		free(layer->prev);
	}
	if (stack->start->prev != stack->start)
		free(stack->start->prev);
	free(stack->start);
}
