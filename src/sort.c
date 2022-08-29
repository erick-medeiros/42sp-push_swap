/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:05:43 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/29 17:58:29 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_not_sorted(t_stack *stack_a, t_stack *stack_b);

void	sort_stacks(t_sorting *sorting, t_stack *stack_a, t_stack *stack_b)
{
	t_element	*element;
	int			i;

	element = stack_a->top;
	i = 0;
	while (i < sorting->list_size && stack_not_sorted(stack_a, stack_b))
	{
		if (element->data <= sorting->center_pivot)
			psl(stack_a, stack_b, "pb");
		else
			psl(stack_a, stack_b, "ra");
		element = stack_a->top;
		++i;
	}
}

void	quick_sort(t_sorting *sorting, int start, int end)
{
	int	pivot;
	int	temp;
	int	i;
	int	j;

	if (start >= end)
		return ;
	pivot = sorting->values[end];
	i = start;
	j = start - 1;
	while (++j < end)
	{
		if (sorting->values[j] < pivot)
		{
			temp = sorting->values[j];
			sorting->values[j] = sorting->values[i];
			sorting->values[i] = temp;
			++i;
		}
	}
	temp = sorting->values[i];
	sorting->values[i] = sorting->values[end];
	sorting->values[end] = temp;
	quick_sort(sorting, start, i - 1);
	quick_sort(sorting, i + 1, end);
}

void	set_sorting_information(t_sorting *sorting, t_stack *stack)
{
	t_element	*element;
	int			a;
	int			b;
	int			c;

	sorting->min = 0;
	sorting->max = 0;
	element = stack->top;
	while (element)
	{
		sorting->min = ft_min(sorting->min, element->data);
		sorting->max = ft_max(sorting->max, element->data);
		element = element->next;
	}
	quick_sort(sorting, 0, sorting->list_size - 1);
	a = ft_max((sorting->list_size * 3 / 4) - 1, 0);
	c = ft_max((sorting->list_size / 2) - 1, 0);
	b = ft_max((sorting->list_size * 1 / 4) - 1, 0);
	sorting->a_pivot = sorting->values[a];
	sorting->center_pivot = sorting->values[c];
	sorting->b_pivot = sorting->values[b];
}

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
