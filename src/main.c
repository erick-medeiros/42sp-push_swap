/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:38:38 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/23 20:18:48 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_layer	*layer;

	if (argc == 1)
		return (1);
	create_stack(&stack_a, argc, argv);
	layer = stack_a.start;
	while (layer)
	{
		ft_printf("%i\n", layer->value);
		layer = layer->next;
		if (layer == stack_a.start)
			layer = NULL;
	}
	free_stack(&stack_a);
	return (0);
}
