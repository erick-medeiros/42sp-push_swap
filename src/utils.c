/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:47:24 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/17 10:53:25 by eandre-f         ###   ########.fr       */
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

void	update_stack(t_stack *stack)
{
	t_node	*node;

	stack->size = 0;
	stack->min = 0;
	stack->max = 0;
	node = stack->top;
	while (node)
	{
		if (node == stack->top)
		{
			stack->min = node->data;
			stack->max = node->data;
		}
		else
		{
			stack->min = ft_min(stack->min, node->data);
			stack->max = ft_max(stack->max, node->data);
		}
		++stack->size;
		if (node->next == stack->top)
			node->next = NULL;
		node = node->next;
	}
}

int	stack_is_unsorted(t_stack *stack)
{
	t_node	*node;
	int		previous;
	int		link_max_min;

	if (stack->size == 0)
		return (FALSE);
	previous = stack_value(stack, 1);
	node = stack->top;
	link_max_min = FALSE;
	while (node)
	{
		if (previous == stack->max && node->data == stack->min)
			link_max_min = TRUE;
		if (link_max_min)
			if (node != stack->top && node->data > stack->top->data)
				return (TRUE);
		if (node != stack->top && node->data < previous)
			if (previous != stack->max || node->data != stack->min)
				return (TRUE);
		previous = node->data;
		node = node->next;
	}
	return (FALSE);
}

int	stack_value(t_stack *stack, int position)
{
	t_node	*node;
	int		i;
	int		value;

	if (position <= 0)
		position = stack->size;
	--position;
	value = 0;
	i = 0;
	node = stack->top;
	while (node && i != position)
	{
		node = node->next;
		++i;
	}
	if (node)
		value = node->data;
	return (value);
}
