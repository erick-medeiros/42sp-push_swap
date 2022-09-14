/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:28:03 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/14 17:14:47 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

static void	create_stack(t_stack *stack, int argc, char *argv[])
{
	t_element	*current;
	t_element	*last;
	int			i;

	i = argc - 1;
	last = NULL;
	while (i >= 1)
	{
		current = malloc(sizeof(t_element));
		if (current == NULL)
			return ;
		current->next = last;
		current->data = ft_atoi(argv[i]);
		last = current;
		--i;
	}
	stack->top = last;
}

void	init_sort(t_sort *sort, int argc, char *argv[])
{
	int	value;
	int	size;
	int	i;

	create_stack(&sort->stack_a, argc, argv);
	sort->stack_b.top = NULL;
	sort->min = 0;
	sort->max = 0;
	size = stack_size(&sort->stack_a);
	i = -1;
	while (++i < size)
	{
		value = stack_value(&sort->stack_a, i + 1);
		sort->min = ft_min(sort->min, value);
		sort->max = ft_max(sort->max, value);
	}
}

void	init_move(t_move *move, int index_a, int index_b, int id)
{
	move->ra = 0;
	move->rra = 0;
	move->rb = 0;
	move->rrb = 0;
	move->rr = 0;
	move->rrr = 0;
	move->total = 0;
	move->index_a = index_a;
	move->index_b = index_b;
	move->id = id;
}

t_move	*clone_move(t_move *move)
{
	t_move	*clone;

	clone = malloc(sizeof(t_move));
	if (!clone)
		return (NULL);
	clone->ra = move->ra;
	clone->rra = move->rra;
	clone->rb = move->rb;
	clone->rrb = move->rrb;
	clone->rr = move->rr;
	clone->rrr = move->rrr;
	clone->total = move->total;
	clone->index_a = move->index_a;
	clone->index_b = move->index_b;
	clone->id = move->id;
	return (clone);
}
