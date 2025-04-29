/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:28:23 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/29 17:07:58 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_list(t_stack **a)
{
	t_stack	*tmp;
	int		count;

	count = 0;
	tmp = *a;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

int	small_value(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*start;

	start = *a;
	tmp = (*a)->next;
	while (start != NULL && tmp != NULL)
	{
		if (start->number < tmp->number)
			tmp = tmp->next;
		else
		{
			start = tmp;
			tmp = tmp->next;
		}
	}
	return (start->number);
}

void	if_else(t_stack **b, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rb(b, size);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			rrb(b, size);
			pos--;
		}
	}
}
