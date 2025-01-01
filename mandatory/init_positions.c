/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_positions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:27:04 by aalahyan          #+#    #+#             */
/*   Updated: 2024/12/31 20:21:59 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_array(long *nums, int i, int j)
{
	long	temp;

	temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

static int	partition(long *nums, int low, int high)
{
	long	pivot;
	int		temp;

	pivot = nums[low];
	temp = low;
	while (low < high)
	{
		while (low < high && nums[low] <= pivot)
			low++;
		while (nums[high] > pivot)
			high--;
		if (low < high)
			swap_array(nums, low, high);
	}
	swap_array(nums, temp, high);
	return (high);
}

static void	quick_sort_array(long *nums, int low, int high)
{
	int	j;

	if (low < high)
	{
		j = partition(nums, low, high);
		quick_sort_array(nums, low, j - 1);
		quick_sort_array(nums, j + 1, high);
	}
}

static int	get_position(long *nums, int val, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((int)nums[i] == val)
			return (i);
		i++;
	}
	return (i);
}

void	init_positions(t_stack *a, long *numbers, int count)
{
	t_stack	*temp;

	quick_sort_array(numbers, 0, count - 1);
	temp = a;
	while (temp->next != a)
	{
		temp->position = get_position(numbers, temp->value, count);
		temp = temp->next;
	}
	temp->position = get_position(numbers, temp->value, count);
}
