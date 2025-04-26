/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:50:18 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/26 20:36:27 by miaghabe         ###   ########.fr       */
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

void	sorting(t_stack *a, t_stack *b)
{
	int	len;
	int	*arr;

	len = size_list(&a);
	arr = list_to_arr(&a, len);
	arr_sort(arr, len);
	init_index(&a, arr, len);
	free(arr);
	if (len == 2)
		sort_2(&a);
	else if (len == 3)
		sort_3(&a);
	else if (len == 4)
		sort_4(&a, &b);
	else if (len == 5)
		sort_5(&a, &b);
	else
		butterfly(&a, &b, get_n(len));
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (!init_args(argv, &a))
		return (1);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	sorting(a, b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
