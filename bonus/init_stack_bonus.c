/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:27:20 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/02 12:22:10 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static bool	append_node(t_stack **a, int value, int index)
{
	t_stack	*node;
	t_stack	*last;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (false);
	node->index = index;
	node->value = value;
	node->next = NULL;
	if (!*a)
	{
		*a = node;
		return (true);
	}
	last = get_last_node(*a);
	last->next = node;
	return (true);
}

bool	init_stack(t_stack **a, long *nums, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!append_node(a, (int)nums[i], i))
		{
			clear_stack(a);
			return (false);
		}
		i++;
	}
	return (true);
}
