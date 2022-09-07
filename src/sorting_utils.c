/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:47:24 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/07 10:42:23 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	pivot_separated_stack(t_stack *stack, int pivot)
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

int	best_top_move(t_stack *stack, int number)
{
	t_element	*element;
	int			found;
	int			move1;
	int			move2;

	move1 = 0;
	move2 = 0;
	found = 0;
	element = stack->top;
	while (element)
	{
		if (element->data == number)
			found = 1;
		if (found)
			++move2;
		else
			++move1;
		element = element->next;
	}
	if (move1 > move2)
		return (1);
	else
		return (2);
}

int	next_element(t_sorting *sorting, t_stack *stack_a)
{
	int			number;
	int			i;

	number = 0;
	if (stack_a->top)
		number = stack_a->top->data;
	i = 0;
	while (i < sorting->list_size && sorting->values[i] != number)
		++i;
	if (sorting->values[i] == number)
	{
		if (i + 1 < sorting->list_size)
			++i;
		return (sorting->values[i]);
	}
	return (0);
}

int	best_pulling_move(t_stack *stack, int pivot)
{
	t_element	*element;
	int			found;
	int			move1;
	int			move2;

	move1 = 0;
	move2 = 0;
	found = 0;
	element = stack->top;
	while (element)
	{
		if (element->data <= pivot)
		{
			found = 1;
			move2 = 0;
		}
		if (found)
			++move2;
		else
			++move1;
		element = element->next;
	}
	if (move1 <= move2)
		return (1);
	return (2);
}
