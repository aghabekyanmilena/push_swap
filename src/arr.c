/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:14:41 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/24 22:15:38 by miaghabe         ###   ########.fr       */
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

void	init_index(t_stack **stack, int *arr, int size)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	while (tmp != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == tmp->number)
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

int	minimum(t_stack **a)
{
	t_stack	*tmp;
	int		data;
	int		min_pos;
	int		index;

	if (*a == NULL)
		return (-1);

	tmp = *a;
	data = tmp->number;
	min_pos = 0;
	index = 0;
	while (tmp)
	{
		if (tmp->number < data)
		{
			data = tmp->number;
			min_pos = index;
		}
		tmp = tmp->next;
		index++;
	}
	return (min_pos);
}

void	min_pos_rev(t_stack **list, int min_pos)
{
	if (min_pos == 0)
		return ;
	while (min_pos != 0)
	{
		if (min_pos > 0)
		{
			ra(list);
			min_pos--;
		}
		else
		{
			rra(list);
			min_pos++;
		}
	}
}
