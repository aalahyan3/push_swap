/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   booleans.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:00:36 by aalahyan          #+#    #+#             */
/*   Updated: 2024/12/31 23:15:55 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	valid_numbers(long *numbers, int count)
{
	int	i;
	int	j;

	i = 0;
	if (!numbers)
		return (false);
	while (i < count)
	{
		j = i + 1;
		if (numbers[i] > INT_MAX || numbers[i] < INT_MIN)
			return (false);
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				return (free(numbers), false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	is_stack_sorted(t_stack *stack)
{
	t_stack	*temp;
	int		min;

	min = stack->value;
	temp = stack;
	while (temp->next != stack)
	{
		if (temp->value < min)
			return (false);
		min = temp->value;
		temp = temp->next;
	}
	if (temp->value < min)
		return (false);
	return (true);
}
