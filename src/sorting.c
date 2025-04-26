/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:57:32 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/25 14:10:21 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **a) // sort 2 petqa qnarkel
{
	t_stack	*tmp;

	tmp = *a;
	if (is_sorted(*a))
		return ;
	if (tmp->number > tmp->next->number)
		sa(a);
}

// sort 3y ashxatum er bayc bolor casery cher vor ashxatum er
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

// sort 4i depqy petqa qnarkel te che seg er qcum
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

// static int	get_max_bits(t_stack *stack)
// {
// 	int		max_index = 0;
// 	int		max_bits = 0;

// 	while (stack)
// 	{
// 		if (stack->index > max_index)
// 			max_index = stack->index;
// 		stack = stack->next;
// 	}
// 	while ((max_index >> max_bits) != 0)
// 		max_bits++;
// 	return (max_bits);
// }

// void	butterfly_sort(t_stack **a, t_stack **b)
// {
// 	int		i;
// 	int		j;
// 	int		size;
// 	int		max_bits;

// 	size = size_list(a);
// 	max_bits = get_max_bits(*a);
// 	i = 0;
// 	while (i < max_bits)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			if (((*a)->index >> i) & 1)
// 				ra(a);
// 			else
// 				pb(a, b);
// 			j++;
// 		}
// 		while (*b)
// 			pa(a, b);
// 		i++;
// 	}
// }
