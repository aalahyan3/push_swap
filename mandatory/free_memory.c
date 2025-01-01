/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:58:51 by aalahyan          #+#    #+#             */
/*   Updated: 2024/12/31 20:21:28 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_splited_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
	array = NULL;
}

void	clear_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*aux;

	if (!*stack || !stack)
		return ;
	temp = *stack;
	while (temp->next != *stack)
	{
		aux = temp->next;
		free(temp);
		temp = aux;
	}
	free(temp);
	*stack = NULL;
}
