/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:46:50 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/29 19:08:33 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack);
	while (*stack && stack)
	{
		tmp = tmp ->next;
		free(*stack);
		*stack = tmp;
	}
}

void	print_error(t_stack **stack)
{
	if (stack)
		free_stack(stack);
	write (2, "Error\n", 6);
	exit(1);
}

bool	ft_atolli(char *arg, t_stack **a, int sign)
{
	long long int	res;
	(void)a;

	res = 0;
	while (*arg && (*arg == 32 || (*arg >= 9 && *arg <= 13)))
		arg++;
	if (*arg == '-')
	{
		sign *= -1;
		arg++;
	}
	else if (*arg == '+')
		arg++;
	while (*arg && *arg == '0')
		arg++;
	if (ft_strlen(arg) > 11)
		return (false);
	while (*arg && (*arg >= '0' && *arg <= '9'))
	{
		res = res * 10 + (*arg - '0');
		arg++;
	}
	if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
		return (false);
	return (true);
}

void	rrr(t_stack **a, t_stack **b, int i)
{
	rra(a, i);
	rrb(b, i);
	if (i)
		ft_putstr_fd("rrr\n", 1);
}
