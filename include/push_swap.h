/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:20:00 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/06 14:40:44 by eandre-f         ###   ########.fr       */
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

typedef struct s_sorting
{
	int	list_size;
	int	*values;
	int	a_pivot;
	int	b_pivot;
	int	center_pivot;
	int	min;
	int	max;
}	t_sorting;

int		check_args(int argc, char *argv[]);
void	free_stack(t_stack *stack);
void	psl(t_stack *stack_a, t_stack *stack_b, char *instruction);
void	create_stack(t_stack *stack, int argc, char *argv[]);
void	update_bottom_stack(t_stack *stack);
void	sort_stacks(t_sorting *sorting, t_stack *stack_a, t_stack *stack_b);
int		stack_not_sorted(t_stack *stack_a, t_stack *stack_b);
void	set_sorting_information(t_sorting *sorting, t_stack *stack);
void	get_values_from_stack(t_sorting *sorting, t_stack *stack);

#endif