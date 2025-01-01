/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:13:07 by aalahyan          #+#    #+#             */
/*   Updated: 2024/12/31 20:22:21 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	phase_1(t_stack **a, t_stack **b)
{
	int	size_a;
	int	pushed;
	int	i;

	size_a = get_stack_size(*a);
	pushed = 0;
	i = 0;
	while (size_a > 6 && i < size_a && pushed < size_a / 2)
	{
		if ((*a)->position <= size_a / 2)
		{
			push(a, b, 'b');
			pushed++;
		}
		else
			rotate(a, 'a', true);
		i++;
	}
	while (size_a - pushed > 3)
	{
		push(a, b, 'b');
		pushed++;
	}
}
