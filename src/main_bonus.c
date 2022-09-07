/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:30:16 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/07 20:20:05 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	t_stack		stack_a;
	t_stack		stack_b;
	char		*str;
	int			is_sorted;

	if (argc == 1)
		return (0);
	if (check_args(argc, argv))
		exit_program(1, "Error", STDERR);
	create_stack(&stack_a, argc, argv);
	stack_b.top = NULL;
	str = get_next_line(0);
	while (str)
	{
		ft_strupd(&str, ft_substr(str, 0, ft_strlen(str) - 1));
		psl(&stack_a, &stack_b, str);
		ft_strupd(&str, get_next_line(0));
	}
	is_sorted = stack_not_sorted(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (is_sorted == 0)
		exit_program(0, "OK", STDOUT);
	else
		exit_program(1, "Error", STDERR);
}
