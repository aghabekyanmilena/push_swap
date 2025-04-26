/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:05:41 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/26 17:44:45 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_log2(size_t n)
{
	size_t	log;

	if (n == 0)
		return (0);
	log = 0;
	while (n)
	{
		n >>= 1;
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

void	butterfly(t_stack **a, t_stack **b, int n)
{
	t_stack	*tmp;
	int		counter;

	counter = 0;
	tmp = *a;
	while (*a)
	{
		if (tmp->index <= counter)
		{
			pb(a, b);
			rb(b);
			counter++;
		}
		else if (tmp->index <= counter + n)
		{
			pb(a, b);
			counter++;
		}
		else
			ra(a);
	}
	
}