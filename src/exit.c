/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:52:55 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/12 21:56:23 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
	t_element	*element;
	t_element	*free_element;

	if (stack == NULL)
		return ;
	element = stack->top;
	while (element)
	{
		free_element = element;
		element = element->next;
		free(free_element);
	}
	stack->top = NULL;
}

void	free_sort(t_sort *sort)
{
	free_stack(&sort->stack_a);
	free_stack(&sort->stack_b);
	free(sort->values);
}

void	exit_program(int status, char *msg, int fd)
{
	if (ft_strlen(msg) > 0)
		ft_putendl_fd(msg, fd);
	exit(status);
}
