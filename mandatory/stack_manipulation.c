/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:43:34 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/02 12:42:14 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_to_stack(t_stack **to, t_stack *new_elem)
{
	if (!*to)
	{
		*to = new_elem;
		new_elem->next = new_elem;
		new_elem->prev = new_elem;
	}
	else
	{
		new_elem->next = *to;
		new_elem->prev = (*to)->prev;
		(*to)->prev->next = new_elem;
		(*to)->prev = new_elem;
		*to = new_elem;
	}
}

void	push(t_stack **from, t_stack **to, char which)
{
	t_stack	*temp;

	if (!*from)
		return ;
	temp = *from;
	if (*from == (*from)->next)
		*from = NULL;
	else
	{
		*from = temp->next;
		(*from)->prev = temp->prev;
		temp->prev->next = *from;
	}
	add_to_stack(to, temp);
	ft_printf("p%c\n", which);
}

void	swap(t_stack **stack, char which)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !(*stack) || !(*stack)->next || *stack == (*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	first->prev->next = second;
	first->prev = second;
	*stack = second;
	ft_printf("s%c\n", which);
}

void	rotate(t_stack **stack, char which, bool print)
{
	if (!*stack || !(*stack)->next || *stack == (*stack)->next)
		return ;
	*stack = (*stack)->next;
	if (print)
		ft_printf("r%c\n", which);
}

void	reverse_rotate(t_stack **stack, char which, bool print)
{
	if (!*stack || !(*stack)->next || *stack == (*stack)->next)
		return ;
	*stack = (*stack)->prev;
	if (print)
		ft_printf("rr%c\n", which);
}
