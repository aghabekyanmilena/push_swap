/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:57:32 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/26 20:36:14 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	if (is_sorted(*a))
		return ;
	if (tmp->number > tmp->next->number)
		sa(a);
}

void	sort_3(t_stack **list)
{
	int	a;
	int	b;
	int	c;

	a = (*list)->index;
	b = (*list)->next->index;
	c = (*list)->next->next->index;
	if (a > b && a < c)
		sa(list);
	else if (a < b && a > c)
		rra(list);
	else if (a > b && a > c && b < c)
		ra(list);
	else if (a > b && a > c && b > c)
	{
		sa(list);
		rra(list);
	}
	else if (a < b && a < c && b > c)
	{
		sa(list);
		ra(list);
	}
}

void	sort_4(t_stack **a, t_stack **b)
{
	int		min_pos;

	if (is_sorted(*a))
		return ;
	min_pos = minimum(a);
	min_pos_rev(a, min_pos);
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	count;
	int	min_pos;

	count = 2;
	if (is_sorted(*a))
		return ;
	while (count > 0)
	{
		min_pos = minimum(a);
		min_pos_rev(a, min_pos);
		pb(a, b);
		count--;
	}
	sort_3(a);
	pa(a, b);
	pa(a, b);
}
