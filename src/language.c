/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   language.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:27:55 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/16 10:53:02 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push swap language == psl

enum e_rotate {
	ROTATE_UP,
	ROTATE_DOWN
};

static void	psl_mult(t_sort *sort, char *instruction);
static void	psl_swap(t_stack *stack);
static void	psl_push(t_stack *stack_origin, t_stack *stack_destiny);
static void	psl_rotate(t_stack *stack, int rotate);

void	psl(t_sort *sort, char *instruction)
{
	if (sort->print)
		ft_putendl_fd(instruction, STDOUT);
	if (!ft_strcmp(instruction, "sa"))
		psl_swap(sort->stack_a);
	else if (!ft_strcmp(instruction, "sb"))
		psl_swap(sort->stack_b);
	else if (!ft_strcmp(instruction, "ss"))
		psl_mult(sort, instruction);
	else if (!ft_strcmp(instruction, "pa"))
		psl_push(sort->stack_b, sort->stack_a);
	else if (!ft_strcmp(instruction, "pb"))
		psl_push(sort->stack_a, sort->stack_b);
	else if (!ft_strcmp(instruction, "ra"))
		psl_rotate(sort->stack_a, ROTATE_UP);
	else if (!ft_strcmp(instruction, "rb"))
		psl_rotate(sort->stack_b, ROTATE_UP);
	else if (!ft_strcmp(instruction, "rr"))
		psl_mult(sort, instruction);
	else if (!ft_strcmp(instruction, "rra"))
		psl_rotate(sort->stack_a, ROTATE_DOWN);
	else if (!ft_strcmp(instruction, "rrb"))
		psl_rotate(sort->stack_b, ROTATE_DOWN);
	else if (!ft_strcmp(instruction, "rrr"))
		psl_mult(sort, instruction);
}

static void	psl_mult(t_sort *sort, char *instruction)
{
	if (!ft_strcmp(instruction, "ss"))
	{
		psl_swap(sort->stack_a);
		psl_swap(sort->stack_b);
	}
	else if (!ft_strcmp(instruction, "rr"))
	{
		psl_rotate(sort->stack_a, ROTATE_UP);
		psl_rotate(sort->stack_b, ROTATE_UP);
	}
	else if (!ft_strcmp(instruction, "rrr"))
	{
		psl_rotate(sort->stack_a, ROTATE_DOWN);
		psl_rotate(sort->stack_b, ROTATE_DOWN);
	}
}

static void	psl_swap(t_stack *stack)
{
	t_node	*top;
	t_node	*next;

	top = stack->top;
	if (top == NULL || top->next == NULL)
		return ;
	next = top->next;
	top->next = next->next;
	next->next = top;
	stack->top = next;
	update_stack(stack);
}

static void	psl_push(t_stack *stack_origin, t_stack *stack_destiny)
{
	t_node	*node;

	if (stack_origin->top == NULL)
		return ;
	node = stack_origin->top;
	stack_origin->top = node->next;
	node->next = stack_destiny->top;
	stack_destiny->top = node;
	update_stack(stack_origin);
	update_stack(stack_destiny);
}

static void	psl_rotate(t_stack *stack, int rotate)
{
	t_node	*top;
	t_node	*bot;

	top = stack->top;
	bot = stack->top;
	while (bot && bot->next)
		bot = bot->next;
	if (top == NULL || top == bot)
		return ;
	if (rotate == ROTATE_UP)
	{
		stack->top = top->next;
		top->next = NULL;
		bot->next = top;
	}
	else if (rotate == ROTATE_DOWN)
	{
		bot->next = top;
		stack->top = bot;
	}
	update_stack(stack);
}
