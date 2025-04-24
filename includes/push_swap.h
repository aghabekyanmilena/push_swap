/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:15:24 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/24 22:37:47 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
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
} t_stack;

// helper functions
void	print_error(void);
void	free_split(char **split);
int		ft_atolli(char *arg);
void	free_stack(t_stack **stack);
void	push_back(t_stack **stack, int number);
void	print_stack(t_stack *stack);

// validation functions
int		check_doubles(t_stack *stack, int number);
int		check_empty(char *argument);
int		is_number(char *argument);
int		init_args(char **argv, t_stack **a);
int		is_sorted(t_stack *a);

// operations a
void	sa(t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rra(t_stack **a);

// operations b
void	sb(t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rb(t_stack **b);
void	rrb(t_stack **b);

// operations
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// new 
int		*list_to_arr(t_stack **stack, int size);//es em avelacrel
int		minimum(t_stack **a);
void	arr_sort(int *arr, int size);// sael
void	init_index(t_stack **stack, int *arr, int size);
void	print_arr(int *arr, int size);
void	print_index(t_stack **stack);
void	move_to_top(t_stack **a, int min_pos);
void	min_pos_rev(t_stack **list, int min_pos);
void	sort_2(t_stack **a);
void	sort_3(t_stack **list);
void	sort_4(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);
int		size_list(t_stack **a);

#endif