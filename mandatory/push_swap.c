/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:42:28 by aalahyan          #+#    #+#             */
/*   Updated: 2024/12/31 20:41:12 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	if (!*a || !a)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->prev->value;
	if (first > second && first > third)
	{
		rotate(a, 'a', true);
		if (second > third)
			swap(a, 'a');
	}
	if (second > first && second > third)
	{
		reverse_rotate(a, 'a', true);
		if (first < third)
			swap(a, 'a');
	}
	if (third > second && third > first && first > second)
		swap(a, 'a');
}

void	sort_large(t_stack	**a, t_stack **b)
{
	t_stack	*min;

	phase_1(a, b);
	sort_three(a);
	phase_2(a, b);
	fill_indexes(*a, NULL);
	fill_median_bool(*a, get_stack_size(*a));
	min = get_min_node(*a);
	if (min->near_top)
	{
		while (*a != min)
			rotate(a, 'a', true);
	}
	else
	{
		while (*a != min)
			reverse_rotate(a, 'a', true);
	}
}

void	push_swap(t_stack **a, t_stack **b, int count)
{
	if (is_stack_sorted(*a))
		return ;
	if (count == 2)
		swap(a, 'a');
	if (count == 3)
		sort_three(a);
	else
		sort_large(a, b);
}
