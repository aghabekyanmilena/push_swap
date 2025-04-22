/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:04:44 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/22 16:23:58 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(t_stack *stack, int number)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->number == number)
			count++;
		stack = stack->next;
	}
	if (count >= 1)
		return (0);
	return (1);
}

int	check_empty(char *argument)
{
	int	i;
	int	flag;

	if (*argument == '\0')
		return (0);
	i = 0;
	flag = 0;
	while (argument[i])
	{
		if (argument[i] != ' ')
			flag = 1;
		i++;
	}
	if (!flag)
		return (0);
	return (1);
}

int	is_number(char *argument)
{
	int	i;

	i = 0;
	while (argument[i])
	{
		if (!ft_isdigit(argument[i]) && argument[i] != '-' && argument[i] != '+'
			&& argument[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	valid_arguments(t_stack **stack, char *arg, char *args[])
{
	(void)args;
	if (!check_empty(arg))
		return (0);
	if (!is_number(arg))
		return (0);
	if (ft_atolli(arg)) // sharunakel
	if (!check_doubles(*stack, ft_atoi(arg)))
		return (0);
	return (1);
}
