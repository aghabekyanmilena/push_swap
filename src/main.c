/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:50:18 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/23 18:59:22 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->next && stack->next->number < stack->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("Number: %d\n", stack->number);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	// t_stack	*b;

	a = NULL;
	// b = NULL;
	if (argc == 1)
		return (0);
	init_args(argv, &a);
	if (is_sorted(a))
		return (0);
	sort_3(&a);
	print_stack(a);
}
