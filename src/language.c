/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   language.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:27:55 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/15 10:57:06 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push swap language == psl

static void	psl_mult(t_stack *stack_a, t_stack *stack_b, char *instruction);
static void	psl_swap(t_stack *stack);
static void	psl_push(t_stack *stack_origin, t_stack *stack_destiny);
static void	psl_rotate(t_stack *stack, char *direction);

void	psl(t_sort *sort, char *instruction)
{
	if (sort->print)
		ft_putendl_fd(instruction, STDOUT);
	if (!ft_strcmp(instruction, "sa"))
		psl_swap(&sort->stack_a);
	else if (!ft_strcmp(instruction, "sb"))
		psl_swap(&sort->stack_b);
	else if (!ft_strcmp(instruction, "ss"))
		psl_mult(&sort->stack_a, &sort->stack_b, "ss");
	else if (!ft_strcmp(instruction, "pa"))
		psl_push(&sort->stack_b, &sort->stack_a);
	else if (!ft_strcmp(instruction, "pb"))
		psl_push(&sort->stack_a, &sort->stack_b);
	else if (!ft_strcmp(instruction, "ra"))
		psl_rotate(&sort->stack_a, "first");
	else if (!ft_strcmp(instruction, "rb"))
		psl_rotate(&sort->stack_b, "first");
	else if (!ft_strcmp(instruction, "rr"))
		psl_mult(&sort->stack_a, &sort->stack_b, "rr");
	else if (!ft_strcmp(instruction, "rra"))
		psl_rotate(&sort->stack_a, "last");
	else if (!ft_strcmp(instruction, "rrb"))
		psl_rotate(&sort->stack_b, "last");
	else if (!ft_strcmp(instruction, "rrr"))
		psl_mult(&sort->stack_a, &sort->stack_b, "rrr");
}

static void	psl_mult(t_stack *stack_a, t_stack *stack_b, char *instruction)
{
	if (!ft_strcmp(instruction, "ss"))
	{
		psl_swap(stack_a);
		psl_swap(stack_b);
	}
	else if (!ft_strcmp(instruction, "rr"))
	{
		psl_rotate(stack_a, "first");
		psl_rotate(stack_b, "first");
	}
	else if (!ft_strcmp(instruction, "rrr"))
	{
		psl_rotate(stack_a, "last");
		psl_rotate(stack_b, "last");
	}
}

static void	psl_swap(t_stack *stack)
{
	t_element	*top;
	t_element	*next;

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
	t_element	*element;

	if (stack_origin->top == NULL)
		return ;
	element = stack_origin->top;
	stack_origin->top = element->next;
	element->next = stack_destiny->top;
	stack_destiny->top = element;
	update_stack(stack_origin);
	update_stack(stack_destiny);
}

static void	psl_rotate(t_stack *stack, char *direction)
{
	t_element	*top;
	t_element	*bot;

	top = stack->top;
	bot = stack->top;
	while (bot && bot->next)
		bot = bot->next;
	if (top == NULL || top == bot)
		return ;
	if (!ft_strcmp(direction, "first"))
	{
		stack->top = top->next;
		top->next = NULL;
		bot->next = top;
	}
	else if (!ft_strcmp(direction, "last"))
	{
		bot->next = top;
		stack->top = bot;
	}
	update_stack(stack);
}
