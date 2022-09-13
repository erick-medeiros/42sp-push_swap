/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:20:00 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/13 15:05:19 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

enum e_instructions
{
	RUN_NONE,
	RUN_SA,
	RUN_SB,
	RUN_SS,
	RUN_PA,
	RUN_PB,
	RUN_RA,
	RUN_RB,
	RUN_RR,
	RUN_RRB,
};

typedef struct s_element
{
	int		data;
	void	*next;
}	t_element;

typedef struct s_stack
{
	t_element	*top;
}	t_stack;

typedef struct s_sort
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		list_size;
	int		*values;
	int		min;
	int		max;
}	t_sort;

typedef struct s_move
{
	int	total;
	int	new_top;
}	t_move;

int		check_args(int argc, char *argv[]);
void	exit_program(int status, char *msg, int fd);
void	free_sort(t_sort *sort);
void	init_sort(t_sort *sort, int argc, char *argv[]);
void	psl(t_stack *stack_a, t_stack *stack_b, char *instruction);
void	update_bottom_stack(t_stack *stack);
void	quick_sort(int **values, int start, int end);
int		get_center_pivot(t_stack *stack);
int		stack_size(t_stack *stack);
int		stack_value(t_stack *stack, int position);
int		stack_index(t_stack *stack, int value);
int		stack_not_sorted(t_stack *stack_a, t_stack *stack_b);
int		pivot_separated_stack(t_stack *stack, int pivot);
void	best_top_move_a(t_stack *stack_a, t_stack *stack_b, int value);
int		best_pulling_move(t_stack *stack, int pivot);
void	sort_stacks(t_sort *sort);
int		best_pulling_to_a(t_sort *sort);
int		best_value_to_pull_b(t_sort *sort, int index_b);
void	pulling_to_top_a(t_sort *sort, int value);

#endif