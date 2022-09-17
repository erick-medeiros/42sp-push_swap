/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:20:00 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/17 16:25:41 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define TRUE 1
# define FALSE 0

typedef struct s_node
{
	int		data;
	void	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
	int		min;
	int		max;
}	t_stack;

typedef struct s_sort
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		min;
	int		max;
	int		print;
}	t_sort;

typedef struct s_move
{
	int	index_a;
	int	index_b;
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rr;
	int	rrr;
	int	total;
}	t_move;

int		check_args(int argc, char *argv[]);
void	exit_program(int status, char *msg, int fd);
void	free_sort(t_sort *sort);
void	init_sort(t_sort *sort, int argc, char *argv[]);
void	init_move(t_move *move, int index_a, int index_b);
t_move	*clone_move(t_move *move);
void	psl(t_sort *sort, char *instruction);
int		get_center_pivot(t_stack *stack, int divison);
void	update_stack(t_stack *stack);
int		stack_value(t_stack *stack, int position);
int		stack_is_unsorted(t_stack *stack);
void	sort_stacks(t_sort *sort);
t_move	*movement_b_to_a(t_sort *sort);
t_move	*movement_a_to_b(t_sort *sort, int pivot);
int		run_ss(t_sort *sort);
int		run_sa(t_sort *sort);
int		run_sa_last(t_sort	*sort);
int		run_sb_last(t_sort *sort);
void	swap_stack(t_sort *sort, char *instruction);

#endif