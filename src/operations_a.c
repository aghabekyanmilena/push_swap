/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:33:20 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/26 20:37:03 by miaghabe         ###   ########.fr       */
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
	ft_putendl_fd("sa", 1);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	ft_putendl_fd("pa", 1);
}

void	ra(t_stack **a)
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
	ft_putendl_fd("ra", 1);
}

void	rra(t_stack **a)
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
	ft_putendl_fd("rra", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	ft_putendl_fd("ss", 1);
}
