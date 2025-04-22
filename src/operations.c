/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:33:20 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/22 19:53:05 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int tmp;

	if (!a || a->next == NULL)
		return ;
	tmp = a->number;
	a->number = a->next->number;
	a->next->number = tmp;
}