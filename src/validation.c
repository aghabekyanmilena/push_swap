/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:04:44 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/21 18:23:32 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_doubles(t_stack *stack)
{
	int	count;
	t_stack	*tmp;

	tmp = stack;
	while (stack)
	{
		count = 0;
		while (tmp)
		{
			if (stack->number == tmp->number)
				count++;
			tmp = tmp->next;
		}
		if (count > 1)
			print_error();
		stack = stack->next;
	}
}

void	check_empty(char *argument)
{
	int	i;
	int	flag;

	if (*argument == '\0')
		print_error();
	i = 0;
	flag = 0;
	while (argument[i])
	{
		if (argument[i] != ' ')
			flag = 1;
		i++;
	}
	if (!flag)
		print_error();
}

void	is_number(char *argument)
{
	int	i;

	i = 0;
	while (argument[i])
	{
		if (!ft_isdigit(argument[i]) && (argument[i] != '-' || argument[i] != '+'))
			print_error();
		i++;
	}
}

void	valid_arguments(t_stack **stack, char *arg, int argc, char *args[])
{
	int	num;

	check_empty(arg);
	is_number(arg);
	num = ft_atolli(stack, arg, argc, args);
	push_back(stack, num);
}