/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:46:31 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/22 15:12:21 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_indexes(t_stack *stack)
{
	int		index;
	t_stack	*cur;
	t_stack	*tmp;

	tmp = stack;
	while (stack)
	{
		cur = tmp;
		index = 0;
		while (cur)
		{
			if (stack->number > cur->number)
				index++;
			cur = cur->next;
		}
		stack->index = index;
		stack = stack->next;
	}
}


void	init_args(char **argv, int argc, t_stack **stack)
{
	int		i;
	char	**arguments;

	i = 0;
	if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	else
	{
		arguments = argv;
		i = 1;
	}
	while (arguments[i])
	{
		if (!valid_arguments(stack, arguments[i], argv))
			print_error();
		push_back(stack, ft_atoi(arguments[i]));
		i++;
	}
	get_indexes(*stack);
	if (argc == 2)
		free_split(arguments);
}

void	push_back(t_stack **stack, int number)
{
	t_stack	*new;
	t_stack	*temp;

	new = malloc(sizeof(t_stack));
	if (!new)
		print_error();
	new->number = number;
	new->next = NULL;

	if (!*stack)
		*stack = new;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}
