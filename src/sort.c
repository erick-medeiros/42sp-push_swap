/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:05:43 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/24 17:28:42 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stacks_debug_ptr(t_stack *stack_a, t_stack *stack_b);

void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	psl(stack_a, stack_b, "sa");
	psl(stack_a, stack_b, "sb");
	psl(stack_a, stack_b, "ss");
	psl(stack_a, stack_b, "pa");
	psl(stack_a, stack_b, "pb");
	psl(stack_a, stack_b, "ra");
	psl(stack_a, stack_b, "rb");
	psl(stack_a, stack_b, "rr");
	psl(stack_a, stack_b, "rra");
	psl(stack_a, stack_b, "rrb");
	psl(stack_a, stack_b, "rrr");
	stacks_debug_ptr(stack_a, stack_b);
}
