/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:22:22 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/28 18:47:52 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (min_pos <= size_list(a) / 2)
		return (min_pos);
	else
		return (min_pos - size_list(a));
}

void	min_pos_rev(t_stack **list, int min_pos, int i)
{
	int	size;

	size = size_list(list);
	if (min_pos == 0)
		return ;
	if (min_pos > 0 && min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(list, i);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < 0)
		{
			rra(list, i);
			min_pos++;
		}
	}
}
