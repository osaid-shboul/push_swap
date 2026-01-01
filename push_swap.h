/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalshbou <oalshbou@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:06:21 by oalshbou          #+#    #+#             */
/*   Updated: 2026/01/01 21:49:27 by oalshbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack
{
	int			value;
	int			index;
	struct s_stack *next;
} t_stack;

long ft_atoi_check(const char *str, int *e);
int check_dublicates(int *num, int count);
void sa(t_stack **stack_a);
void pb(t_stack **stack_a, t_stack **stack_b);
void ra(t_stack **stack_a);
void rra(t_stack **stack_a);
t_stack *ft_stack_new(int value);
void free_stack(t_stack **stack);
void assign_index(t_stack *stack_a, int stack_size);
t_stack *fill_stack(int argc, char **argv);

#endif
