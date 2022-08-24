/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:05:43 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/24 15:03:26 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_layer	*layer;

	psl(stack_a, stack_b, "pb");
	psl(stack_a, stack_b, "ra");
	layer = stack_a->start;
	while (layer)
	{
		layer = layer->next;
		if (layer == stack_a->start)
			layer = NULL;
	}
}
