/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:55:59 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/02 12:23:12 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	if (!*from)
		return ;
	temp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = temp;
}

void	swap(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = get_last_node(*stack);
	first = *stack;
	*stack = (*stack)->next;
	last->next = first;
	first->next = NULL;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*prelast;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = get_last_node(*stack);
	prelast = *stack;
	while (prelast->next->next)
		prelast = prelast->next;
	prelast->next = NULL;
	last->next = *stack;
	*stack = last;
}
