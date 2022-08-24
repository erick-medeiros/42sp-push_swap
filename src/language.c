/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   language.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:27:55 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/24 15:02:59 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// push swap language == psl

static void	psl_mult(t_stack *stack_a, t_stack *stack_b, char *instruction);
static void	psl_swap(t_stack *stack);
static void	psl_push(t_stack *stack_origin, t_stack *stack_destiny);
static void	psl_rotate(t_stack *stack, char *direction);

void	psl(t_stack *stack_a, t_stack *stack_b, char *instruction)
{
	ft_putendl_fd(instruction, STDOUT);
	if (!ft_strcmp(instruction, "sa"))
		psl_swap(stack_a);
	else if (!ft_strcmp(instruction, "sb"))
		psl_swap(stack_b);
	else if (!ft_strcmp(instruction, "ss"))
		psl_mult(stack_a, stack_b, "ss");
	else if (!ft_strcmp(instruction, "pa"))
		psl_push(stack_b, stack_a);
	else if (!ft_strcmp(instruction, "pb"))
		psl_push(stack_a, stack_b);
	else if (!ft_strcmp(instruction, "ra"))
		psl_rotate(stack_a, "first");
	else if (!ft_strcmp(instruction, "rb"))
		psl_rotate(stack_b, "first");
	else if (!ft_strcmp(instruction, "rr"))
		psl_mult(stack_a, stack_b, "rr");
	else if (!ft_strcmp(instruction, "rra"))
		psl_rotate(stack_a, "last");
	else if (!ft_strcmp(instruction, "rrb"))
		psl_rotate(stack_b, "last");
	else if (!ft_strcmp(instruction, "rrr"))
		psl_mult(stack_a, stack_b, "rrr");
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
	t_layer	*layer0;
	t_layer	*layer1;
	t_layer	*layer2;
	t_layer	*layer3;

	layer0 = stack->start->prev;
	layer1 = stack->start;
	layer2 = stack->start->next;
	layer3 = ((t_layer *)(stack->start->next))->next;
	layer0->next = layer2;
	layer3->prev = layer1;
	stack->start = layer2;
}

static void	psl_push(t_stack *stack_origin, t_stack *stack_destiny)
{
	t_layer	*layer0;
	t_layer	*layer1;
	t_layer	*layer2;

	if (stack_origin->start == NULL)
		return ;
	layer0 = stack_origin->start->prev;
	layer1 = stack_origin->start;
	layer2 = stack_origin->start->next;
	layer0->next = layer2;
	layer2->prev = layer0;
	stack_origin->start = layer2;
	layer0 = layer1;
	layer2 = layer1;
	if (stack_destiny->start)
		layer0 = stack_destiny->start->prev;
	if (stack_destiny->start)
		layer2 = stack_destiny->start;
	layer1->prev = layer0;
	layer1->next = layer2;
	layer0->next = layer1;
	layer2->prev = layer1;
	stack_destiny->start = layer1;
}

static void	psl_rotate(t_stack *stack, char *direction)
{
	t_layer	*layer;

	if (!ft_strcmp(direction, "first"))
	{
		layer = stack->start;
		stack->start = layer->next;
	}
	else if (!ft_strcmp(direction, "last"))
	{
		layer = stack->start;
		stack->start = layer->prev;
	}
}
