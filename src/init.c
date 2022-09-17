/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:28:03 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/17 12:56:34 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

static void	create_stack(t_stack *stack, int argc, char *argv[])
{
	t_node	*current;
	t_node	*last;
	int		i;

	i = argc - 1;
	last = NULL;
	while (i >= 1)
	{
		current = malloc(sizeof(t_node));
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
	int	i;

	sort->stack_a = malloc(sizeof(t_stack));
	sort->stack_b = malloc(sizeof(t_stack));
	if (sort->stack_a == NULL || sort->stack_b == NULL)
		exit_program(1, "Error malloc", STDERR);
	create_stack(sort->stack_a, argc, argv);
	sort->stack_b->top = NULL;
	sort->print = TRUE;
	sort->min = stack_value(sort->stack_a, 1);
	sort->max = stack_value(sort->stack_a, 1);
	update_stack(sort->stack_a);
	update_stack(sort->stack_b);
	i = 0;
	while (++i <= sort->stack_a->size)
	{
		value = stack_value(sort->stack_a, i);
		sort->min = ft_min(sort->min, value);
		sort->max = ft_max(sort->max, value);
	}
}

void	init_move(t_move *move, int index_a, int index_b)
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
	return (clone);
}
