/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:57:32 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/28 18:04:42 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **a, int i)
{
	t_stack	*tmp;

	tmp = *a;
	if (is_sorted(*a))
		return ;
	if (tmp->number > tmp->next->number)
		sa(a, i);
}

void	sort_3(t_stack **list, int i)
{
	int	a;
	int	b;
	int	c;

	a = (*list)->index;
	b = (*list)->next->index;
	c = (*list)->next->next->index;
	if (a > b && a < c)
		sa(list, i);
	else if (a < b && a > c)
		rra(list, i);
	else if (a > b && a > c && b < c)
		ra(list, i);
	else if (a > b && a > c && b > c)
	{
		sa(list, i);
		rra(list, i);
	}
	else if (a < b && a < c && b > c)
	{
		sa(list, i);
		ra(list, i);
	}
}

void	sort_4(t_stack **a, t_stack **b, int i)
{
	int		min_pos;

	if (is_sorted(*a))
		return ;
	min_pos = minimum(a);
	min_pos_rev(a, min_pos, i);
	pb(a, b, i);
	sort_3(a, i);
	pa(a, b, i);
}

void	sort_5(t_stack **a, t_stack **b, int i)
{
	int	count;
	int	min_pos;

	count = 2;
	if (is_sorted(*a))
		return ;
	while (count > 0)
	{
		min_pos = minimum(a);
		min_pos_rev(a, min_pos, i);
		pb(a, b, i);
		count--;
	}
	sort_3(a, i);
	pa(a, b, i);
	pa(a, b, i);
}
