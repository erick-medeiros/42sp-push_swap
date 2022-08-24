/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:38:38 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/24 00:40:33 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (check_args(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	create_stack(&stack_a, argc, argv);
	sort_stacks(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
