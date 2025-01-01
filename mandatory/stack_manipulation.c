/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:43:34 by aalahyan          #+#    #+#             */
/*   Updated: 2024/12/31 20:53:50 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!*to)
	{
		*to = temp;
		temp->next = temp;
		temp->prev = temp;
	}
	else
	{
		temp->next = *to;
		temp->prev = (*to)->prev;
		(*to)->prev->next = temp;
		(*to)->prev = temp;
		*to = temp;
	}
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

void	multiple_moves(t_stack **a, t_stack **b, char *move)
{
	if (ft_strncmp(move, "r", 2) == 0)
	{
		rotate(a, 'a', false);
		rotate(b, 'b', false);
		ft_printf("rr\n");
	}
	else
	{
		reverse_rotate(a, 'a', false);
		reverse_rotate(b, 'b', false);
		ft_printf("rrr\n");
	}
}
