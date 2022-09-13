/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:38:38 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/13 16:46:59 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../test/debug.h"

// stacks_debug(&sort.stack_a, &sort.stack_b);
// stacks_debug_ptr(&stack_a, &stack_b);
// debug_values(&sorting);

int	main(int argc, char *argv[])
{
	t_sort	sort;

	if (argc == 1)
		return (0);
	if (check_args(argc, argv))
		exit_program(1, "Error", STDERR);
	init_sort(&sort, argc, argv);
	sort_stacks(&sort);
	free_sort(&sort);
	return (0);
}
