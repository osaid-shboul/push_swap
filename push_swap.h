/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalshbou <oalshbou@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:06:21 by oalshbou          #+#    #+#             */
/*   Updated: 2026/01/02 19:40:37 by oalshbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

long				ft_atoi_check(const char *str, int *e);
int					check_dublicates(t_stack *a);
void				sa(t_stack **stack_a);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				rb(t_stack **stack_b);
void				sb(t_stack **stack_b);
t_stack				*ft_stack_new(int value);
void				free_stack(t_stack **stack);
void				assign_index(t_stack *stack_a);
t_stack				*fill_stack(int argc, char **argv);
int					get_max_index(t_stack *stack);
int					stack_size(t_stack *stack);
t_stack				*find_lastn(t_stack *stack);
void				add_last(t_stack **stack, t_stack *temp);
int					get_target_position(t_stack *stack, int target);
void				sort_three(t_stack **stack_a);
void				sort_five(t_stack **a, t_stack **b);
void				big_sort(t_stack **a, t_stack **b);
t_stack				*fill_stack(int argc, char **argv);
char				**ft_split(char const *s, char c);
int					is_sorted(t_stack *stack);

#endif
