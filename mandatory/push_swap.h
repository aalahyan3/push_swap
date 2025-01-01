/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:38:40 by aalahyan          #+#    #+#             */
/*   Updated: 2024/12/31 23:01:36 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "../libft/libft.h"
/*
already defined in libft
 # include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
*/

typedef struct s_stack
{
	int				value;
	int				index;
	int				position;
	int				cost;
	bool			near_top;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}	t_stack;

// just for testing
void	print_stack(t_stack *stack, char which);
//argument parsing
int		main(int ac, char **av);
long	*parse_arguments(char **args, int count);
void	exit_code(int code);
// free_memory
void	clear_stack(t_stack **stack);
void	free_splited_array(char **array);
//assets
long	ft_atol(const char *str);
t_stack	*get_last_node(t_stack *stack);
int		calculate_numbers(char **args, int count);
int		get_stack_size(t_stack *stack);
t_stack	*get_max_node(t_stack *stack);
void	fill_median_bool(t_stack *stack, int size);
void	calculate_costs(t_stack *stack, int size);
void	fill_indexes(t_stack *a, t_stack *b);
void	init_positions(t_stack *a, long *numbers, int count);
t_stack	*get_min_node(t_stack *stack);
void	get_move(t_stack *stack, char *move, t_stack *target);
//boolean checks
bool	is_number(char *str);
bool	valid_numbers(long *numbers, int count);
bool	init_stack(t_stack **a, long *numbers, int count);
bool	append_node(t_stack **a, int value, int index);
bool	is_stack_sorted(t_stack *stack);
// stack operations
void	push(t_stack **from, t_stack **to, char which);
void	swap(t_stack **stack, char which);
void	rotate(t_stack **stack, char which, bool print);
void	reverse_rotate(t_stack **stack, char which, bool print);
void	push_swap(t_stack **a, t_stack **b, int count);
void	multiple_moves(t_stack **a, t_stack **b, char *move);
// sorting Algorithm
void	phase_1(t_stack **a, t_stack **b);
void	phase_2(t_stack **a, t_stack **b);
void	execute_move(t_stack **stack, char *move, char which);
void	sort_three(t_stack **a);
#endif