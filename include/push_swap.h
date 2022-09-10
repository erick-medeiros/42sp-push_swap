/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:20:00 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/10 20:16:01 by eandre-f         ###   ########.fr       */
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
	int	b_pivot;
	int	center_pivot;
	int	tmp_size;
	int	*tmp_values;
}	t_sorting;

int		check_args(int argc, char *argv[]);
void	free_stack(t_stack *stack);
void	exit_program(int status, char *msg, int fd);
void	psl(t_stack *stack_a, t_stack *stack_b, char *instruction);
void	create_stack(t_stack *stack, int argc, char *argv[]);
void	update_bottom_stack(t_stack *stack);
int		stack_size(t_stack *stack);
int		stack_value(t_stack *stack, int position);
void	set_sorting_information(t_sorting *sorting, t_stack *stack);
void	get_values_from_stack(t_stack *stack, int *list_size, int **values);
void	get_all_elements(t_sorting *sorting, t_stack *stack_a);
int		stack_not_sorted(t_stack *stack_a, t_stack *stack_b);
int		pivot_separated_stack(t_stack *stack, int pivot);
void	swap_top(t_stack *stack_a, t_stack *stack_b, char *instruction);
int		best_top_move(t_stack *stack, int number);
int		next_element(t_sorting *sorting, t_stack *stack_a);
int		best_pulling_move(t_stack *stack, int pivot);
void	sort_stacks(t_sorting *sorting, t_stack *stack_a, t_stack *stack_b);

#endif