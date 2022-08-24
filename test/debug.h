/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:18:21 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/24 17:36:40 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "../include/push_swap.h"

void	stacks_debug(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*element_a;
	t_element	*element_b;

	element_a = stack_a->top;
	element_b = stack_b->top;
	ft_printf("debug:\n");
	while (element_a || element_b)
	{
		if (element_a && element_b)
			ft_printf("%i %i\n", element_a->data, element_b->data);
		else if (element_a)
			ft_printf("%i\n", element_a->data);
		else if (element_b)
			ft_printf("  %i\n", element_b->data);
		if (element_a)
			element_a = element_a->next;
		if (element_b)
			element_b = element_b->next;
	}
	ft_printf("- -\na b\n");
}

void	stacks_debug_ptr(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*element;

	ft_printf("\ndebug:\n");
	ft_printf("\n");
	ft_printf("stack a -> top (%p)\n", stack_a->top);
	element = stack_a->top;
	while (element)
	{
		ft_printf("element -> addr (%p) data (%i) next (%p)\n",
			element, element->data, element->next);
		element = element->next;
	}
	ft_printf("stack b -> top (%p)\n", stack_b->top);
	element = stack_b->top;
	while (element)
	{
		ft_printf("element -> addr (%p) data (%i) next (%p)\n",
			element, element->data, element->next);
		element = element->next;
	}
	ft_printf("\n");
}

#endif