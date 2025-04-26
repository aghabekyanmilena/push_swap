/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:14:41 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/25 13:23:10 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_array_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	*list_to_arr(t_stack **stack, int size)
{
	t_stack	*tmp;
	int		*arr;
	int		i;

	i = 0;
	tmp = *stack;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (i < size && tmp)
	{
		arr[i] = tmp->number;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

void	arr_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
