/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:52:26 by aalahyan          #+#    #+#             */
/*   Updated: 2024/12/31 19:38:48 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_numbers(char **args, int count)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (i < count)
	{
		j = 0;
		while (args[i][j])
		{
			while (args[i][j] && args[i][j] == 32)
				j++;
			if (args[i][j] && args[i][j] != 32)
				counter++;
			while (args[i][j] && args[i][j] != 32)
				j++;
		}
		i++;
	}
	return (counter);
}

long	*parse_arguments(char **args, int count)
{
	int		i;
	int		j;
	int		k;
	long	*numbers;
	char	**temp;

	i = 0;
	k = 0;
	numbers = malloc(sizeof(long) * calculate_numbers(args, count));
	if (!numbers)
		return (NULL);
	while (i < count)
	{
		j = 0;
		temp = ft_split(args[i], ' ');
		while (temp[j] != NULL)
		{
			if (!is_number(temp[j]))
				return (free_splited_array(temp), free(numbers), NULL);
			numbers[k++] = ft_atol(temp[j++]);
		}
		free_splited_array(temp);
		i++;
	}
	return (numbers);
}
