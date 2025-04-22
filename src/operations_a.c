/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:33:20 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/22 22:47:08 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	int	tmp;

	if (!a || !(*a) || (*a)->next == NULL)
		return ;
	tmp = (*a)->number;
	(*a)->number = (*a)->next->number;
	(*a)->next->number = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if ((*b))
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = NULL;
		if ((*a))
			*a = tmp;
		else
		{
			tmp->next = *a;
			*a = tmp;
		}
	}
}

void	ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*var;

	if ((*a)->next)
	{
		var = *a;
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		(*a) = (*a)->next;
		var->next = NULL;
		tmp->next = NULL;
	}
}