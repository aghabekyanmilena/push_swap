/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 22:11:28 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/25 13:26:59 by miaghabe         ###   ########.fr       */
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
	ft_putendl_fd("sb", 1);
}

void	pb(t_stack **a, t_stack **b)// esel em poxel
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	ft_putendl_fd("pb", 1);
}

void	rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*first;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	*b = (*b)->next;
	first->next = NULL;
	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	ft_putendl_fd("rb", 1);
}

void	rrb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (!b || !(*b) || !(*b)->next)
		return ;
	first = NULL;
	last = *b;
	while (last->next)
	{
		first = last;
		last = last->next;
	}
	if (last)
		last->next = NULL;
	first -> next = NULL;
	last->next = *b;
	*b = last;
	ft_putendl_fd("rrb", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	ft_putendl_fd("rr", 1);
}
