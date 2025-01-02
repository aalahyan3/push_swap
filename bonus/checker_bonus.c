/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:26:27 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/02 12:22:34 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	multiple_moves(t_stack **a, t_stack **b, char *command)
{
	if (ft_strncmp(command, "rr\n", 3) == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strncmp(command, "rrr\n", 4) == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

bool	execute(t_stack **a, t_stack **b, char *command)
{
	if (ft_strncmp(command, "sa\n", 3) == 0)
		swap(a);
	else if (ft_strncmp(command, "sb\n", 3) == 0)
		swap(b);
	else if (ft_strncmp(command, "ra\n", 3) == 0)
		rotate(a);
	else if (ft_strncmp(command, "rb\n", 3) == 0)
		rotate(b);
	else if (ft_strncmp(command, "pa\n", 3) == 0)
		push(b, a);
	else if (ft_strncmp(command, "pb\n", 3) == 0)
		push(a, b);
	else if (ft_strncmp(command, "rra\n", 4) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(command, "rrb\n", 4) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(command, "rr\n", 3) == 0 || \
	ft_strncmp(command, "rrr\n", 4) == 0)
		multiple_moves(a, b, command);
	else
		return (false);
	return (true);
}

void	check_push_swap(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!execute(a, b, line))
		{
			free(line);
			exit_code(4);
		}
		free(line);
		line = get_next_line(0);
	}
	if (is_stack_sorted(*a) && !(*b))
	{
		ft_printf("OK\n");
	}
	else
	{
		ft_printf("KO\n");
	}
}
