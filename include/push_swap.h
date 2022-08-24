/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:20:00 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/24 18:03:29 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_element
{
	int		data;
	void	*next;
}	t_element;

typedef struct s_stack
{
	t_element	*top;
}	t_stack;

int		check_args(int argc, char *argv[]);
void	free_stack(t_stack *stack);
void	psl(t_stack *stack_a, t_stack *stack_b, char *instruction);
void	create_stack(t_stack *stack, int argc, char *argv[]);
void	update_bottom_stack(t_stack *stack);
void	sort_stacks(t_stack *stack_a, t_stack *stack_b);

#endif