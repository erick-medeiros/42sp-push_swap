/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:01:45 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/13 13:01:10 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	count_to_top(t_sort *sort, int index_b)
{
	int	move1;
	int	move2;
	int	index;
	int	value;

	value = best_value_to_pull_b(sort, index_b);
	if (stack_value(&sort->stack_a, 1) == value)
		return (-1);
	index = stack_index(&sort->stack_a, value) - 1;
	if (index < 0)
		return (-1);
	move1 = index;
	move2 = stack_size(&sort->stack_a) - index;
	if (move1 <= move2)
		return (move1);
	return (move2);
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

int	best_pulling_to_a(t_sort *sort)
{
	t_move	none;
	t_move	sb;
	t_move	rb;
	t_move	rrb;

	if (stack_index(&sort->stack_a, best_value_to_pull_b(sort, 1)) == 1)
		return (0);
	none.total = count_to_top(sort, 1);
	none.new_top = stack_value(&sort->stack_b, 2);
	sb.total = count_to_top(sort, 2) + 1;
	if (stack_size(&sort->stack_b) <= 2)
		return (1);
	sb.new_top = stack_value(&sort->stack_b, 1);
	rb.total = count_to_top(sort, 2) + 1;
	rb.new_top = stack_value(&sort->stack_b, 3);
	rrb.total = count_to_top(sort, stack_size(&sort->stack_b)) + 1;
	rrb.new_top = stack_value(&sort->stack_b, stack_size(&sort->stack_b) - 1);
	if (none.total <= ft_min(rb.total, rrb.total) && none.total <= sb.total)
		return (4);
	if (sb.total <= ft_min(rb.total, rrb.total))
		return (1);
	if (rb.total <= ft_min(sb.total, rrb.total))
		return (2);
	if (rrb.total <= ft_min(sb.total, rb.total))
		return (3);
	return (4);
}

void	pulling_to_top_a(t_sort *sort, int value)
{
	int	move1;
	int	move2;
	int	index;

	if (stack_value(&sort->stack_a, 1) == value)
		return ;
	index = stack_index(&sort->stack_a, value) - 1;
	if (index < 0)
		return ;
	move1 = index;
	move2 = stack_size(&sort->stack_a) - index;
	if (move1 <= move2)
		while (stack_value(&sort->stack_a, 1) != value)
			psl(&sort->stack_a, &sort->stack_b, "ra");
	else
		while (stack_value(&sort->stack_a, 1) != value)
			psl(&sort->stack_a, &sort->stack_b, "rra");
}

int	best_value_to_pull_b(t_sort *sort, int index_b)
{
	int	i;
	int	nbr;
	int	value_b;
	int	value_a;
	int	len;

	value_b = stack_value(&sort->stack_b, index_b);
	i = 0;
	nbr = value_b;
	len = stack_size(&sort->stack_a);
	while (++i <= len)
	{
		value_a = stack_value(&sort->stack_a, i);
		if (nbr == value_b && value_a > value_b)
			nbr = value_a;
		if (value_a > value_b && value_a < nbr)
			nbr = value_a;
	}
	return (nbr);
}
