/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:30:43 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/06 15:22:38 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_values_from_stack(t_stack *stack, int *list_size, int **values)
{
	t_element	*element;
	size_t		len;

	*values = NULL;
	len = 0;
	element = stack->top;
	while (element && ++len)
		element = element->next;
	*list_size = len;
	if (len == 0)
		return ;
	*values = malloc(sizeof(int) * len);
	if (*values != NULL)
	{
		len = 0;
		element = stack->top;
		while (element)
		{
			*values[len] = element->data;
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
	int			b;
	int			c;

	get_values_from_stack(stack, &(sorting->tmp_size), &sorting->tmp_values);
	quick_sort(sorting, 0, sorting->tmp_size - 1);
	c = ft_max((sorting->tmp_size / 2) - 1, 0);
	b = ft_max((sorting->tmp_size / 4) - 1, 0);
	sorting->center_pivot = sorting->tmp_values[c];
	sorting->b_pivot = sorting->tmp_values[b];
}
