/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:19:02 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/24 22:37:00 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		printf("%d -> ", tmp->number);
		tmp = tmp->next;
	}
	printf ("NULL\n");
}

void	print_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d, ", arr[i]);
		i++;
	}
	printf ("\n");
}

void	print_index(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	printf ("list index - ");
	while (tmp)
	{
		printf("%d -> ", tmp->index);
		tmp = tmp->next;
	}
	printf ("\n");
}
// printeri hamar arandin file