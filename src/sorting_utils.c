/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:47:24 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/13 16:38:07 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	best_top_move_a(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	size;
	int	ra_i;
	int	rra_i;
	int	i;

	size = stack_size(stack_a);
	i = 0;
	ra_i = 0;
	while (++i <= size && stack_value(stack_a, i) == value)
		++ra_i;
	i = size + 1;
	rra_i = 0;
	while (--i > 0 && stack_value(stack_a, i) == value)
		++rra_i;
	i = 0;
	if (ra_i <= rra_i)
		while (++i <= ra_i)
			psl(stack_a, stack_b, "ra");
	else
		while (++i <= rra_i)
			psl(stack_a, stack_b, "rra");
}

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
