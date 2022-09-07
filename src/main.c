/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:38:38 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/07 20:25:24 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../test/debug.h"

// stacks_debug(&stack_a, &stack_b);
// stacks_debug_ptr(&stack_a, &stack_b);
// debug_values(&sorting);

int	main(int argc, char *argv[])
{
	t_sorting	sorting;
	t_stack		stack_a;
	t_stack		stack_b;

	if (argc == 1)
		return (0);
	if (check_args(argc, argv))
		exit_program(1, "Error", STDERR);
	create_stack(&stack_a, argc, argv);
	stack_b.top = NULL;
	get_all_elements(&sorting, &stack_a);
	sort_stacks(&sorting, &stack_a, &stack_b);
	free(sorting.values);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
