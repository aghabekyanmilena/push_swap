/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 22:11:28 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/22 22:48:11 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b)
{
	int	tmp;

	if (!b || !(*b) || (*b)->next == NULL)
		return ;
	tmp = (*b)->number;
	(*b)->number = (*b)->next->number;
	(*b)->next->number = tmp;
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if ((*a))
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		if ((*b))
			*b = tmp;
		else
		{
			tmp->next = *b;
			*b = tmp;
		}
	}
}

void	rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*var;

	if ((*b)->next)
	{
		var = *b;
		tmp = *b;
		while (tmp->next)
			tmp = tmp->next;
		(*b) = (*b)->next;
		var->next = NULL;
		tmp->next = NULL;
	}
}