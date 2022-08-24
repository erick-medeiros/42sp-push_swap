/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:38:38 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/24 14:56:19 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stacks_debug(t_stack *stack_a, t_stack *stack_b);

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		return (0);
	if (check_args(argc, argv))
	{
		ft_putendl_fd("Error", STDERR);
		return (1);
	}
	create_stack(&stack_a, argc, argv);
	stack_b.start = NULL;
	sort_stacks(&stack_a, &stack_b);
	stacks_debug(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}

void	stacks_debug(t_stack *stack_a, t_stack *stack_b)
{
	t_layer	*layer_a;
	t_layer	*layer_b;

	layer_a = stack_a->start;
	layer_b = stack_b->start;
	ft_printf("debug:\n");
	while (layer_a || layer_b)
	{
		if (layer_a && layer_b)
			ft_printf("%i %i\n", layer_a->value, layer_b->value);
		else if (layer_a)
			ft_printf("%i\n", layer_a->value);
		else if (layer_b)
			ft_printf("  %i\n", layer_b->value);
		if (layer_a)
			layer_a = layer_a->next;
		if (layer_b)
			layer_b = layer_b->next;
		if (layer_a == stack_a->start)
			layer_a = NULL;
		if (layer_b == stack_b->start)
			layer_b = NULL;
	}
	ft_printf("- -\na b\n");
}
