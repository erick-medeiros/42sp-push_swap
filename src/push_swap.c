/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:05:43 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/24 00:08:06 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_layer	*layer;

	layer = stack_a->start;
	while (layer)
	{
		ft_printf("%i\n", layer->value);
		layer = layer->next;
		if (layer == stack_a->start)
			layer = NULL;
	}
}
