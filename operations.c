/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalshbou <oalshbou@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:30:24 by oalshbou          #+#    #+#             */
/*   Updated: 2025/12/30 23:39:11 by oalshbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack **stack_a)
{
	t_stack *first;
	t_stack *second;

	if (!*stack_a || !(*stack_a)->next)
		return;

	first = *stack_a;
	second = (*stack_a)->next;

	first->next = second->next;
	second->next = first;
	*stack_a = second;

	write(1, "sa\n", 3);
}

void pb(t_stack **stack, t_stack **stack_a)
{
	t_stack *temp;

	if (!stack_a)
		return;

	temp = *stack_a;
	*stack_a = (*stack_a)->next;

	temp->next = *stack_a;
	*stack_a = temp;

	write(1, "pb\n", 3);
}

void ra(t_stack **stack_a)
{
	t_stack *first;
	t_stack *last;

	if (!*stack_a || !(*stack_a)->next)
		return;
	first = *stack_a;
	*stack_a = first->next;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}
void rra(t_stack **stack_a)
{
	t_stack *last;
	t_stack *blast;

	if (!*stack_a || !(*stack_a)->next)
		return;
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
