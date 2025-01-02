/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:14:58 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/02 12:41:08 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}				t_stack;

int		main(int ac, char **av);
bool	is_stack_sorted(t_stack *stack);
int		calculate_numbers(char **args, int count);
long	*parse_arguments(char **args, int count);
bool	is_number(char *str);
bool	valid_numbers(long *numbers, int count);
bool	is_stack_sorted(t_stack *stack);
void	free_splited_array(char **array);
void	clear_stack(t_stack **stack);
long	ft_atol(const char *str);
t_stack	*get_last_node(t_stack *stack);
bool	init_stack(t_stack **a, long *nums, int count);
void	push(t_stack **from, t_stack **to);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	exit_code(int code);
void	check_push_swap(t_stack **a, t_stack **b);
#endif