/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:18:21 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/16 10:59:16 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "../include/push_swap.h"
# include <stddef.h>

void	stacks_debug(t_sort *sort)
{
	t_node	*node_a;
	t_node	*node_b;

	node_a = sort->stack_a->top;
	node_b = sort->stack_b->top;
	ft_printf("debug:\n");
	while (node_a || node_b)
	{
		if (node_a && node_b)
			ft_printf("%i | %i\n", node_a->data, node_b->data);
		else if (node_a)
			ft_printf("%i |\n", node_a->data);
		else if (node_b)
			ft_printf(" | %i\n", node_b->data);
		if (node_a)
			node_a = node_a->next;
		if (node_b)
			node_b = node_b->next;
	}
	ft_printf("- -\na b\n");
}

void	stacks_debug_ptr(t_sort *sort)
{
	t_node	*node;

	ft_printf("\ndebug:\n");
	ft_printf("\n");
	ft_printf("stack a -> top (%p)\n", sort->stack_a->top);
	node = sort->stack_a->top;
	while (node)
	{
		ft_printf("node -> addr (%p) data (%i) next (%p)\n",
			node, node->data, node->next);
		node = node->next;
	}
	ft_printf("stack b -> top (%p)\n", sort->stack_b->top);
	node = sort->stack_b->top;
	while (node)
	{
		ft_printf("node -> addr (%p) data (%i) next (%p)\n",
			node, node->data, node->next);
		node = node->next;
	}
	ft_printf("\n");
}

void	debug_move(t_move *move)
{
	ft_printf("move ra %i rb %i rr %i rra %i rrb %i rrr %i\n",
		move->ra, move->rb, move->rr, move->rra, move->rrb, move->rrr);
}

#endif