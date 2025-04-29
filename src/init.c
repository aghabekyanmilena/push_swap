/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:46:31 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/29 18:51:34 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*join_args(char **argv)
{
	int		i;
	char	*argument;
	char	*tmp;

	i = 1;
	argument = ft_strdup("");
	while (argv[i])
	{
		if (!check_empty(argv[i]))
			return (free(argument), NULL);
		tmp = ft_strjoin(argument, argv[i]);
		free(argument);
		argument = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	return (argument);
}

void	init_args(char **argv, t_stack **a)
{
	char	*argument;
	char	**split;

	argument = join_args(argv);
	if (argument == NULL)
		print_error(a);
	split = ft_split(argument, "\t\r\v\n\f ");
	free(argument);
	if (!split)
		print_error(a);
	parse_split(split, a);
	free_split(split);
}

void	push_back(t_stack **stack, int number)
{
	t_stack	*new;
	t_stack	*temp;

	new = malloc(sizeof(t_stack));
	if (!new)
		print_error(stack);
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
