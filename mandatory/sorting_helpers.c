/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:46:21 by aalahyan          #+#    #+#             */
/*   Updated: 2024/12/31 20:41:40 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_indexes(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*temp;

	temp = a;
	i = 0;
	while (temp->next != a)
	{
		temp->index = i++;
		temp = temp->next;
	}
	temp->index = i;
	if (!b)
		return ;
	i = 0;
	temp = b;
	while (temp->next != b)
	{
		temp->index = i++;
		temp = temp->next;
	}
	temp->index = i;
}

void	get_move(t_stack *stack, char *move, t_stack *target)
{
	if (stack == target)
	{
		move[0] = '\0';
		return ;
	}
	if (target->near_top)
		ft_strlcpy(move, "r", 3);
	else
		ft_strlcpy(move, "rr", 3);
}

void	fill_median_bool(t_stack *stack, int size)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != stack)
	{
		if (temp->index <= size / 2)
			temp->near_top = true;
		else
			temp->near_top = false;
		temp = temp->next;
	}
	if (temp->index <= size / 2)
		temp->near_top = true;
	else
		temp->near_top = false;
}

void	calculate_costs(t_stack *stack, int size)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != stack)
	{
		if (temp->near_top)
			temp->cost = temp->index;
		else
			temp->cost = size - temp->index;
		temp = temp->next;
	}
	if (temp->near_top)
		temp->cost = temp->index;
	else
		temp->cost = size - temp->index;
}

void	execute_move(t_stack **stack, char *move, char which)
{
	if (!*move)
		return ;
	if (ft_strncmp(move, "r", 2) == 0)
	{
		rotate(stack, which, true);
	}
	else
		reverse_rotate(stack, which, true);
}
