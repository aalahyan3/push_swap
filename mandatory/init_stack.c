/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:05:17 by aalahyan          #+#    #+#             */
/*   Updated: 2024/12/31 20:22:11 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	append_node(t_stack **a, int value, int index)
{
	t_stack	*new;
	t_stack	*last;

	last = get_last_node(*a);
	new = malloc(sizeof(t_stack));
	if (!new)
		return (false);
	last->next = new;
	new->next = *a;
	(*a)->prev = new;
	new->prev = last;
	new->value = value;
	new->index = index;
	new->target = NULL;
	new->near_top = false;
	return (true);
}

bool	init_stack(t_stack **a, long *numbers, int count)
{
	int	i;

	*a = malloc(sizeof(t_stack));
	if (!(*a))
		return (false);
	i = 0;
	while (i < count)
	{
		if (i == 0)
		{
			(*a)->index = i;
			(*a)->value = numbers[i];
			(*a)->next = *a;
			(*a)->prev = *a;
			(*a)->target = NULL;
			(*a)->near_top = false;
		}
		else
			if (!append_node(a, numbers[i], i))
				return (clear_stack(a), false);
		i++;
	}
	return (true);
}
