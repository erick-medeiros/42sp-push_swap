/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:38:38 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/24 00:04:19 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		return (1);
	create_stack(&stack_a, argc, argv);
	sort_stacks(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
