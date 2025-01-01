/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:03:05 by aalahyan          #+#    #+#             */
/*   Updated: 2024/12/31 20:20:58 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str && (*str == 32 || (*str >= 9 && *str <= 13)))
		str++;
	if (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

t_stack	*get_last_node(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next != stack)
		tmp = tmp->next;
	return (tmp);
}

int	get_stack_size(t_stack *stack)
{
	t_stack	*temp;
	int		size;

	if (!stack)
		return (0);
	size = 0;
	temp = stack;
	while (temp->next != stack)
	{
		size++;
		temp = temp->next;
	}
	size++;
	return (size);
}

t_stack	*get_max_node(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*max;

	temp = stack;
	max = stack;
	while (temp->next != stack)
	{
		if (temp->value > max->value)
			max = temp;
		temp = temp->next;
	}
	if (temp->value > max->value)
		max = temp;
	return (max);
}

t_stack	*get_min_node(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*min;

	temp = stack;
	min = stack;
	while (temp->next != stack)
	{
		if (temp->value < min->value)
			min = temp;
		temp = temp->next;
	}
	if (temp->value < min->value)
		min = temp;
	return (min);
}
