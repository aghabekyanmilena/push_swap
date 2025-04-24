/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:46:31 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/24 22:21:38 by miaghabe         ###   ########.fr       */
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


int	init_args(char **argv, t_stack **a)
{
	int		i;
	char	*argument;
	char	**split;

	i = 1;
	argument = ft_strdup("");
	while (argv[i])
	{
		if (!check_empty(argv[i]))
			return (print_error(), 0);
		argument = ft_strjoin(argument, argv[i]);
		argument = ft_strjoin(argument, " ");
		i++;
	}
	split = ft_split(argument, ' ');
	i = 0;
	free(argument);
	while (split[i])
	{
		if (!is_number(split[i]))
			return (free_split(split), print_error(), 0);
		if (!check_doubles(*a, ft_atoi(split[i])))
			return (free_split(split), print_error(), 0);
		push_back(a, ft_atoi(split[i]));
		i++;
	}
	get_indexes(*a);
	return (free_split(split), 1);
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
