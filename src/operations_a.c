/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:33:20 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/28 18:46:38 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int i)
{
	int	tmp;

	if (!a || !(*a) || (*a)->next == NULL)
		return ;
	tmp = (*a)->number;
	(*a)->number = (*a)->next->number;
	(*a)->next->number = tmp;
	if (i)
		ft_putstr_fd("sa\n", 1);
}

void	pa(t_stack **a, t_stack **b, int i)
{
	t_stack	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	if (i)
		ft_putstr_fd("pa\n", 1);
}

void	ra(t_stack **a, int i)
{
	t_stack	*tmp;
	t_stack	*first;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	*a = (*a)->next;
	first->next = NULL;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	if (i)
		ft_putstr_fd("ra\n", 1);
}

void	rra(t_stack **a, int i)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = NULL;
	last = *a;
	while (last->next)
	{
		first = last;
		last = last->next;
	}
	if (last)
		last->next = NULL;
	first->next = NULL;
	last->next = *a;
	*a = last;
	if (i)
		ft_putstr_fd("rra\n", 1);
}

void	ss(t_stack **a, t_stack **b, int i)
{
	sa(a, i);
	sb(b, i);
	if (i)
		ft_putstr_fd("ss\n", 1);
}
