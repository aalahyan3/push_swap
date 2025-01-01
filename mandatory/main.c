/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:38:53 by aalahyan          #+#    #+#             */
/*   Updated: 2024/12/31 20:59:20 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_code(int code)
{
	ft_putendl_fd("Error", 2);
	exit(code);
}

void	print_stack(t_stack *stack, char which)
{
	t_stack	*temp;

	temp = stack;
	if (!stack)
	{
		ft_printf("stack %c: Empty\n", which);
		return ;
	}
	ft_printf("stack %c: ", which);
	while (temp->next != stack)
	{
		ft_printf("%d -> ", temp->value);
		temp = temp->next;
	}
	ft_printf("%d\n", temp->value);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	long	*numbers;
	int		count;

	a = NULL;
	b = NULL;
	if (ac < 2)
		exit_code(1);
	numbers = parse_arguments(av + 1, ac - 1);
	count = calculate_numbers(av + 1, ac - 1);
	if (!valid_numbers(numbers, count))
		exit_code(2);
	if (!init_stack(&a, numbers, count))
		exit_code(3);
	init_positions(a, numbers, count);
	push_swap(&a, &b, count);
	free(numbers);
	clear_stack(&a);
	clear_stack(&b);
}
