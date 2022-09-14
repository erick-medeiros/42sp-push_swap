/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:30:16 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/14 19:42:35 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	t_sort	sort;
	char	*str;
	int		is_sorted;

	if (argc == 1)
		return (1);
	if (check_args(argc, argv))
		exit_program(1, "Error", STDERR);
	init_sort(&sort, argc, argv);
	str = get_next_line(STDIN);
	while (str)
	{
		ft_strupd(&str, ft_substr(str, 0, ft_strlen(str) - 1));
		psl(&sort.stack_a, &sort.stack_b, str);
		ft_strupd(&str, get_next_line(STDIN));
	}
	is_sorted = stack_not_sorted(&sort.stack_a, &sort.stack_b);
	free_sort(&sort);
	if (is_sorted == 0)
		exit_program(0, "OK", STDOUT);
	else
		exit_program(1, "Error", STDERR);
}
