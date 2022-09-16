/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:47:24 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/16 10:24:56 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quick_sort(int **values, int start, int end)
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

int	get_center_pivot(t_stack *stack, int division)
{
	int	list_size;
	int	*values;
	int	i;
	int	pivot;

	list_size = stack->size;
	values = malloc(sizeof(int) * list_size);
	if (values == NULL)
		return (0);
	i = -1;
	while (++i < list_size)
		values[i] = stack_value(stack, i + 1);
	quick_sort(&values, 0, list_size - 1);
	i = ft_max((list_size / division) - 1, 0);
	i = ft_min(i, list_size - 1);
	i = ft_max(i, 0);
	pivot = values[i];
	free(values);
	return (pivot);
}

int	run_ss(t_sort *sort)
{
	if (sort->stack_a->size >= 3 && sort->stack_b->size >= 3
		&& stack_value(sort->stack_a, 1) > stack_value(sort->stack_a, 2)
		&& stack_value(sort->stack_b, 1) < stack_value(sort->stack_b, 2))
		return (TRUE);
	return (FALSE);
}
