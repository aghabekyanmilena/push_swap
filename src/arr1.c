/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:22:22 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/25 13:23:37 by miaghabe         ###   ########.fr       */
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