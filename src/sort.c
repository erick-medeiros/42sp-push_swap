/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:05:43 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/06 18:39:10 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_not_sorted(t_stack *stack_a, t_stack *stack_b)
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

static int	pivot_separated_stack(t_stack *stack, int pivot)
{
	t_element	*element;

	element = stack->top;
	while (element)
	{
		if (element->data <= pivot)
			return (1);
		element = element->next;
	}
	return (0);
}

static void	swap_top(t_stack *stack_a, t_stack *stack_b, char *instruction)
{
	if (!ft_strcmp(instruction, "sa"))
	{
		if (stack_a->top && stack_a->top->next)
			if (stack_a->top->data > ((t_element *)(stack_a->top->next))->data)
				psl(stack_a, stack_b, "sa");
	}
	else if (!ft_strcmp(instruction, "sb"))
	{
		if (stack_b->top && stack_b->top->next)
			if (stack_b->top->data < ((t_element *)(stack_b->top->next))->data)
				psl(stack_a, stack_b, "sb");
	}
}

void	sort_stacks(t_sorting *sorting, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	while (stack_not_sorted(stack_a, stack_b) && stack_size(stack_a) > 2)
	{
		set_sorting_information(sorting, stack_a);
		i = 0;
		while (stack_not_sorted(stack_a, stack_b)
			&& pivot_separated_stack(stack_a, sorting->center_pivot))
		{
			if (stack_a->top && stack_a->top->data <= sorting->center_pivot)
				psl(stack_a, stack_b, "pb");
			else
				psl(stack_a, stack_b, "ra");
			swap_top(stack_a, stack_b, "sb");
			++i;
		}
		free(sorting->tmp_values);
	}
	swap_top(stack_a, stack_b, "sa");
}
