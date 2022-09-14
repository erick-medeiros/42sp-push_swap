/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:38:38 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/14 19:34:56 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../test/debug.h"

// stacks_debug(&sort);
// stacks_debug_ptr(&sort);
// debug_values(&sort);

int	main(int argc, char *argv[])
{
	t_sort	sort;

	if (argc == 1)
		return (1);
	if (check_args(argc, argv))
		exit_program(1, "Error", STDERR);
	init_sort(&sort, argc, argv);
	sort_stacks(&sort);
	free_sort(&sort);
	return (0);
}
