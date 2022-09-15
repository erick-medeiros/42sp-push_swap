/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:30:16 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/15 00:36:51 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>

static int	is_valid(char *str)
{
	if (ft_strcmp(str, "pa") == 0)
		return (TRUE);
	else if (ft_strcmp(str, "pb") == 0)
		return (TRUE);
	else if (ft_strcmp(str, "sa") == 0)
		return (TRUE);
	else if (ft_strcmp(str, "sb") == 0)
		return (TRUE);
	else if (ft_strcmp(str, "ss") == 0)
		return (TRUE);
	else if (ft_strcmp(str, "ra") == 0)
		return (TRUE);
	else if (ft_strcmp(str, "rb") == 0)
		return (TRUE);
	else if (ft_strcmp(str, "rr") == 0)
		return (TRUE);
	else if (ft_strcmp(str, "rra") == 0)
		return (TRUE);
	else if (ft_strcmp(str, "rrb") == 0)
		return (TRUE);
	else if (ft_strcmp(str, "rrr") == 0)
		return (TRUE);
	return (FALSE);
}

static void	sorting(t_sort *sort)
{
	char	*str;

	str = get_next_line(STDIN);
	while (str)
	{
		ft_strupd(&str, ft_substr(str, 0, ft_strlen(str) - 1));
		psl(sort, str);
		if (is_valid(str) == FALSE)
		{
			free(str);
			free_sort(sort);
			exit_program(1, "Error", STDERR);
		}
		ft_strupd(&str, get_next_line(STDIN));
	}
}

int	main(int argc, char *argv[])
{
	t_sort	sort;
	int		is_sorted;

	if (argc == 1)
		return (1);
	if (check_args(argc, argv))
		exit_program(1, "Error", STDERR);
	init_sort(&sort, argc, argv);
	sorting(&sort);
	is_sorted = stack_not_sorted(&sort);
	free_sort(&sort);
	if (is_sorted == 0)
		exit_program(0, "OK", STDOUT);
	else
		exit_program(1, "KO", STDERR);
}
