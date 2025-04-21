/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:15:24 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/21 17:55:27 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
} t_stack;


// helper functions
void	print_error(void);
void	free_split(char **split);
// initalization
void	init_args(char **argv, int argc, t_stack **stack);
// validation functions
void	check_doubles(t_stack *stack);
void	check_empty(char *argument);
void	is_number(char *argument);


#endif