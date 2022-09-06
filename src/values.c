/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:30:43 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/06 14:34:40 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
