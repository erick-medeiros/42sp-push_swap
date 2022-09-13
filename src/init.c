/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:28:03 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/13 00:31:16 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

static void	create_stack(t_stack *stack, int argc, char *argv[])
{
	t_element	*current;
	t_element	*last;
	int			i;

	i = argc - 1;
	last = NULL;
	while (i >= 1)
	{
		current = malloc(sizeof(t_element));
		if (current == NULL)
			return ;
		current->next = last;
		current->data = ft_atoi(argv[i]);
		last = current;
		--i;
	}
	stack->top = last;
}

void	init_sort(t_sort *sort, int argc, char *argv[])
{
	int	i;

	create_stack(&sort->stack_a, argc, argv);
	sort->stack_b.top = NULL;
	sort->list_size = stack_size(&sort->stack_a);
	sort->values = malloc(sizeof(int) * sort->list_size);
	sort->min = 0;
	sort->max = 0;
	i = -1;
	while (++i < sort->list_size)
	{
		sort->values[i] = stack_value(&sort->stack_a, i + 1);
		sort->min = ft_min(sort->min, sort->values[i]);
		sort->max = ft_max(sort->max, sort->values[i]);
	}
	quick_sort(&sort->values, 0, sort->list_size - 1);
}
