/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:52:27 by aalahyan          #+#    #+#             */
/*   Updated: 2024/12/31 20:40:48 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_target(int value, t_stack *a)
{
	t_stack	*target;
	t_stack	*temp;

	temp = a;
	target = NULL;
	while (temp->next != a)
	{
		if (value < temp->value)
		{
			if (!target || temp->value < target->value)
				target = temp;
		}
		temp = temp->next;
	}
	if (value < temp->value)
	{
		if (!target || temp->value < target->value)
			target = temp;
	}
	if (!target)
		target = get_min_node(a);
	return (target);
}

static void	set_targets(t_stack *a, t_stack *b)
{
	t_stack	*temp;

	temp = b;
	while (temp->next != b)
	{
		temp->target = get_target(temp->value, a);
		temp = temp->next;
	}
	temp->target = get_target(temp->value, a);
}

static t_stack	*get_node_to_move(t_stack *b)
{
	t_stack	*temp;
	t_stack	*to_move;
	int		deal;

	temp = b;
	to_move = NULL;
	deal = INT_MAX;
	while (temp->next != b)
	{
		if (deal > temp->cost + temp->target->cost)
		{
			to_move = temp;
			deal = temp->cost + temp->target->cost;
		}
		temp = temp->next;
	}
	if (deal > temp->cost + temp->target->cost)
	{
		to_move = temp;
		deal = temp->cost + temp->target->cost;
	}
	return (to_move);
}

static void	apply_moves(t_stack **a, t_stack **b, t_stack *to_move)
{
	char	move_a[3];
	char	move_b[3];

	while (*b != to_move || *a != to_move->target)
	{
		get_move(*b, move_b, to_move);
		get_move(*a, move_a, to_move->target);
		if (ft_strncmp(move_a, move_b, 2) == 0 && *move_a && *move_b)
			multiple_moves(a, b, move_a);
		else
		{
			execute_move(a, move_a, 'a');
			execute_move(b, move_b, 'b');
		}
	}
}

void	phase_2(t_stack **a, t_stack **b)
{
	int		size_a;
	int		size_b;
	t_stack	*to_move;

	size_a = get_stack_size(*a);
	size_b = get_stack_size(*b);
	while (*b)
	{
		fill_indexes(*a, *b);
		fill_median_bool(*a, size_a);
		fill_median_bool(*b, size_b);
		set_targets(*a, *b);
		calculate_costs(*a, size_a);
		calculate_costs(*b, size_b);
		to_move = get_node_to_move(*b);
		apply_moves(a, b, to_move);
		push(b, a, 'a');
		size_b--;
		size_a++;
	}
}
