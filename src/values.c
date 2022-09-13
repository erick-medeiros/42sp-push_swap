/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:30:43 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/12 21:32:45 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(int **values, int start, int end)
{
	int	pivot;
	int	temp;
	int	i;
	int	j;

	if (start >= end)
		return ;
	pivot = (*values)[end];
	i = start;
	j = start - 1;
	while (++j < end)
	{
		if ((*values)[j] < pivot)
		{
			temp = (*values)[j];
			(*values)[j] = (*values)[i];
			(*values)[i] = temp;
			++i;
		}
	}
	temp = (*values)[i];
	(*values)[i] = (*values)[end];
	(*values)[end] = temp;
	quick_sort(values, start, i - 1);
	quick_sort(values, i + 1, end);
}

int	get_center_pivot(t_stack *stack)
{
	int	list_size;
	int	*values;
	int	i;
	int	pivot;

	list_size = stack_size(stack);
	values = malloc(sizeof(int) * list_size);
	if (values == NULL)
		return (0);
	i = -1;
	while (++i < list_size)
		values[i] = stack_value(stack, i + 1);
	quick_sort(&values, 0, list_size - 1);
	i = ft_max((list_size / 2) - 1, 0);
	pivot = values[i];
	free(values);
	return (pivot);
}
