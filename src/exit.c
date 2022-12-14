/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:52:55 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/16 14:17:36 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ignore_zero_left(char *argv)
{
	char	*ref;

	ref = argv;
	while (ft_strlen(ref) && ref[0] == '0' && ft_isdigit(ref[1]))
		ref = &ref[1];
	return (ref);
}

int	check_args(int argc, char *argv[])
{
	int		i;
	int		j;
	int		cmp;
	char	*str;

	i = 0;
	while (++i < argc)
	{
		str = ft_itoa(ft_atoi(argv[i]));
		cmp = ft_strcmp(str, ignore_zero_left(argv[i]));
		free(str);
		if (cmp)
			return (1);
	}
	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
	}
	return (0);
}

static void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*free_node;

	if (stack == NULL)
		return ;
	node = stack->top;
	while (node)
	{
		free_node = node;
		node = node->next;
		free(free_node);
	}
	stack->top = NULL;
}

void	free_sort(t_sort *sort)
{
	free_stack(sort->stack_a);
	free_stack(sort->stack_b);
	free(sort->stack_a);
	free(sort->stack_b);
}

void	exit_program(int status, char *msg, int fd)
{
	if (ft_strlen(msg) > 0)
		ft_putendl_fd(msg, fd);
	exit(status);
}
