/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:05:41 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/28 18:48:53 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_log2(size_t n)
{
	size_t	log;

	if (n == 0)
		return (0);
	log = 0;
	while (n > 1)
	{
		n /= 2;
		log++;
	}
	return (log);
}

static size_t	ft_sqrt(size_t n)
{
	size_t	left;
	size_t	right;
	size_t	mid;
	size_t	res;

	if (n == 0 || n == 1)
		return (n);
	left = 1;
	right = n / 2 + 1;
	res = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (mid * mid == n)
			return (mid);
		else if (mid * mid < n)
		{
			left = mid + 1;
			res = mid;
		}
		else
			right = mid - 1;
	}
	return (res);
}

size_t	get_n(size_t lstsize)
{
	if (lstsize == 0)
		return (0);
	return ((ft_sqrt(lstsize) * 3) / 2 + ft_log2(lstsize) - 1);
}

void	move_max_to_top(t_stack **b)
{
	t_stack	*tmp;
	int		max;
	int		pos;
	int		size;
	int		i;

	tmp = *b;
	max = tmp->index;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	size = i;
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rb(b, i);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			rrb(b, i);
			pos--;
		}
	}
}

void	butterfly(t_stack **a, t_stack **b, int n, int i)
{
	int		counter;

	counter = 0;
	while (*a)
	{
		if ((*a)->index <= counter)
		{
			pb(a, b, i);
			rb(b, i);
			counter++;
		}
		else if ((*a)->index <= counter + n)
		{
			pb(a, b, i);
			counter++;
		}
		else
			ra(a, i);
	}
	while (*b)
	{
		move_max_to_top(b);
		pa(a, b, i);
	}
}
