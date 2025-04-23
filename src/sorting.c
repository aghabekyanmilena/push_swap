/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:57:32 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/23 21:30:43 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a)
{
	int n1 = (*a)->number;
	int n2 = (*a)->next->number;
	int n3 = (*a)->next->next->number;

	if (n1 > n2 && n2 < n3 && n1 < n3)
		sa(a);
	else if (n1 > n2 && n2 > n3)
	{
		sa(a);
		rra(a);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ra(a);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		sa(a);
		ra(a);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		rra(a);
}

// static int	find_min_position(t_stack *a)
// {
// 	int	min;
// 	int	pos;
// 	int	i;

// 	min = a->number;
// 	pos = 0;
// 	i = 0;
// 	while (a)
// 	{
// 		if (a->number < min)
// 		{
// 			min = a->number;
// 			pos = i;
// 		}
// 		a = a->next;
// 		i++;
// 	}
// 	return (pos);
// }

// static void	bring_min_to_top(t_stack **a, int size)
// {
// 	int	pos;

// 	pos = find_min_position(*a);
// 	if (pos <= size / 2)
// 	{
// 		while (pos-- > 0)
// 			ra(a);
// 	}
// 	else
// 	{
// 		while (pos++ < size)
// 			rra(a);
// 	}
// }


// void	sort_5(t_stack **a, t_stack **b)
// {
// 	bring_min_to_top(a, 5);
// 	pb(a, b);
// 	bring_min_to_top(a, 4);
// 	pb(a, b);
// 	sort_3(a);
// 	pa(a, b);
// 	pa(a, b);
// 	if ((*a)->next)
// 	{
// 		if ((*a)->number > (*a)->next->number)
// 			sa(a);
// 	}
// }

static int size_list(t_stack **a)
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

int small_value(t_stack **a)
{
	t_stack *tmp;
	t_stack *start;

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
	printf("small value %d\n",start->number);
	return (start->number);
}

void move_two_smallest_to_b(int data, int len, t_stack **a, t_stack **b)
{
	int count;
	t_stack *tmp;

	tmp = *a;
	count = 1;
	while (data != tmp->number)
	{
		tmp = tmp->next;
		count++;
	}
	if (len / 2 < count)
	{
		while (tmp->next != NULL)
			rra(a);
		rra(a);
		pb(a, b);
	}
	else
	{
		while (--count)
			ra(a);
		pb(a, b);
	}
}

void sort_5(t_stack **a, t_stack **b)
{
	int		len;
	int		data;
	int		count;

	count = 0;
	while (count < 2)
	{
		data = small_value(a);
		pb(a, b);
		len = size_list(a);
		if (len == 3)
			break;
		count++;
		move_two_smallest_to_b(data, len, a, b);
		// count++;
	}
	sort_3(a);
	pa(a, b);
	pa(a, b);
}
