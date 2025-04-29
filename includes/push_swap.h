/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:15:24 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/29 17:09:19 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}	t_stack;

// helper functions
void	free_split(char **split);
bool	ft_atolli(char *arg, t_stack **a, int sign);
void	free_stack(t_stack **stack);
void	push_back(t_stack **stack, int number);

// validation functions
int		check_doubles(t_stack *stack, int number);
int		check_empty(char *argument);
int		is_number(char *argument);
void	init_args(char **argv, t_stack **a);
int		is_sorted(t_stack *a);

// operations a
void	sa(t_stack **a, int i);
void	pa(t_stack **a, t_stack **b, int i);
void	ra(t_stack **a, int i);
void	rra(t_stack **a, int i);

// operations b
void	sb(t_stack **b, int i);
void	pb(t_stack **a, t_stack **b, int i);
void	rb(t_stack **b, int i);
void	rrb(t_stack **b, int i);

// operations
void	ss(t_stack **a, t_stack **b, int i);
void	rr(t_stack **a, t_stack **b, int i);
void	rrr(t_stack **a, t_stack **b, int i);

// helper functions
int		*list_to_arr(t_stack **stack, int size);
int		minimum(t_stack **a);
int		size_list(t_stack **a);
void	arr_sort(int *arr, int size);
void	init_index(t_stack **stack, int *arr, int size);
void	min_pos_rev(t_stack **list, int min_pos, int i);

// print functions
void	print_error(t_stack **stack);
void	print_stack(t_stack *stack);
void	print_index(t_stack **stack);
void	print_arr(int *arr, int size);

// soting
void	sort_2(t_stack **a, int i);
void	sort_3(t_stack **list, int i);
void	sort_4(t_stack **a, t_stack **b, int i);
void	sort_5(t_stack **a, t_stack **b, int i);

// butterfly
size_t	get_n(size_t lstsize);
void	if_else(t_stack **b, int pos, int size);
void	butterfly(t_stack **a, t_stack **b, int n, int i);

#endif