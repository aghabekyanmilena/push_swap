/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:57:32 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/23 18:58:46 by miaghabe         ###   ########.fr       */
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