/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalshbou <oalshbou@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:30:24 by oalshbou          #+#    #+#             */
/*   Updated: 2026/01/03 15:18:27 by oalshbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	t_stack	*f;
	t_stack	*l;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	f = *stack_b;
	*stack_b = f->next;
	l = *stack_b;
	while (l->next != NULL)
		l = l->next;
	l->next = f;
	f->next = NULL;
	write(1, "rb\n", 3);
}

void	rra(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*blast;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last = *stack_a;
	blast = NULL;
	while (last->next != NULL)
	{
		blast = last;
		last = last->next;
	}
	blast->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*blast;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last = *stack_b;
	blast = NULL;
	while (last->next != NULL)
	{
		blast = last;
		last = last->next;
	}
	blast->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	write(1, "rrb\n", 4);
}
