/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:38:53 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/02 12:22:54 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	while (temp)
	{
		ft_printf("%d -> ", temp->value);
		temp = temp->next;
	}
	ft_printf("NULL\n");
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
		return (0);
	numbers = parse_arguments(av + 1, ac - 1);
	count = calculate_numbers(av + 1, ac - 1);
	if (!valid_numbers(numbers, count))
		exit_code(2);
	if (!init_stack(&a, numbers, count))
		exit_code(3);
	check_push_swap(&a, &b);
	free(numbers);
	clear_stack(&a);
	clear_stack(&b);
}
