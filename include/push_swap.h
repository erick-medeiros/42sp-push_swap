/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:20:00 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/24 00:36:58 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

// order: top-down

typedef struct s_layer
{
	int		value;
	void	*prev;
	void	*next;
}	t_layer;

typedef struct s_stack
{
	t_layer	*start;
}	t_stack;

int		check_args(int argc, char *argv[]);
void	free_stack(t_stack *stack);
void	create_stack(t_stack *stack, int argc, char *argv[]);
void	sort_stacks(t_stack *stack_a, t_stack *stack_b);

#endif