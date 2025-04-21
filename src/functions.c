/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:46:50 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/21 17:55:52 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!*split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	print_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

int	ft_atolli(t_stack **stack, char *arg, int argc, char *args[])
{
	long long int	res;
	int				sign;

	sign = 1;
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
	while (*arg && (*arg >= '0' && *arg <= '9'))
	{
		res = res * 10 + (*arg - '0');
		arg++;
	}
	if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
		ft_error(stack, argc, args); // print_error
	return ((int)(res * sign));
}
