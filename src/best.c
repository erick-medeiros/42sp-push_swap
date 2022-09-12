/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:01:45 by eandre-f          #+#    #+#             */
/*   Updated: 2022/09/12 19:50:43 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	check_valid_a(t_stack *stack_a, int index_a, t_stack *stack_b, int index_b)
{
	if (stack_value(stack_a, index_a) > stack_value(stack_b, index_b)
		&& (stack_value(stack_a, index_a - 1) < stack_value(stack_b, index_b)
			|| stack_value(stack_a, index_a - 1) == 500))
		return (1);
	return (0);
}

static int	check_total_ra(t_stack *stack_a, int value_b)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (++i <= stack_size(stack_a))
	{
		if (stack_value(stack_a, i) > value_b
			&& (stack_value(stack_a, i - 1) < value_b
				|| stack_value(stack_a, i - 1) == 500))
			return (total);
		++total;
	}
	return (total);
}

static int	check_total_rra(t_stack *stack_a, int value_b)
{
	int	total;
	int	i;

	total = 0;
	i = stack_size(stack_a);
	while (i >= 0)
	{
		if (stack_value(stack_a, i) < value_b
			&& stack_value(stack_a, 1) > value_b)
			return (total);
		++total;
		--i;
	}
	return (total);
}

int	best_pulling_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_move	move_sb;
	t_move	move_rb;
	t_move	move_rrb;

	if (check_valid_a(stack_a, 1, stack_b, 1))
		return (0);
	move_sb.valid = 1;
	move_sb.total = ft_min(check_total_ra(stack_a, stack_value(stack_b, 2)),
			check_total_rra(stack_a, stack_value(stack_b, 2)));
	if (stack_size(stack_b) <= 2)
		return (1);
	move_sb.new_top = stack_value(stack_b, 1);
	move_rb.total = move_sb.total;
	move_rb.new_top = stack_value(stack_b, 3);
	move_rrb.total = ft_min(
			check_total_ra(stack_a, stack_value(stack_b, stack_size(stack_b))),
			check_total_rra(stack_a, stack_value(stack_b, stack_size(stack_b)))
			);
	move_rrb.new_top = stack_value(stack_b, stack_size(stack_b) - 1);
	if (move_sb.total <= ft_min(move_rb.total, move_rrb.total))
		return (1);
	if (move_rb.total <= ft_min(move_sb.total, move_rrb.total))
		return (2);
	if (move_rrb.total <= ft_min(move_sb.total, move_rb.total))
		return (3);
	return (0);
}

void	exec_rotate(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	ra;
	int	rra;

	if (check_valid_a(stack_a, 1, stack_b, 1))
		return ;
	ra = check_total_ra(stack_a, stack_value(stack_b, 1));
	rra = check_total_rra(stack_a, stack_value(stack_b, 1));
	i = -1;
	if (ra < rra)
		while (++i < ra && ra != 0)
			psl(stack_a, stack_b, "ra");
	else
		while (++i < rra && rra != 0)
			psl(stack_a, stack_b, "rra");
}

void	exec_rotate_run(t_stack *stack_a, t_stack *stack_b, int value)
{
	if (best_top_move(stack_a, value) == 1)
		while (stack_value(stack_a, stack_size(stack_a)) != value)
			psl(stack_a, stack_b, "ra");
	else
		while (stack_value(stack_a, stack_size(stack_a)) != value)
			psl(stack_a, stack_b, "rra");
}
