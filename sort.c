/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalshbou <oalshbou@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:52:45 by oalshbou          #+#    #+#             */
/*   Updated: 2026/01/14 16:43:43 by oalshbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack **stack_a)
{
	int max;

	if (is_sorted(*stack_a))
		return;
	max = get_max_index(*stack_a);
	if ((*stack_a)->index == max)
		ra(stack_a);
	else if ((*stack_a)->next->index == max)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

void sort_five(t_stack **a, t_stack **b)
{
	int min;
	int pos;
	int size;

	while (stack_size(*a) > 3)
	{
		min = get_min_index(*a);
		pos = get_target_position(*a, min);
		size = stack_size(*a);
		if (pos <= size / 2)
		{
			while ((*a)->index != min)
				ra(a);
		}
		else
		{
			while ((*a)->index != min)
				rra(a);
		}
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

void big_sort_to_b(t_stack **a, t_stack **b, int size)
{
	int i;
	int range;

	i = 0;
	if (size <= 100)
		range = 15;
	else
		range = 35;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
}

void big_sort_to_a(t_stack **a, t_stack **b)
{
	int max;
	int pos;
	int size;

	while (*b)
	{
		max = get_max_index(*b);
		pos = get_target_position(*b, max);
		size = stack_size(*b);
		if (pos <= size / 2)
		{
			while ((*b)->index != max)
				rb(b);
		}
		else
		{
			while ((*b)->index != max)
				rrb(b);
		}
		pa(a, b);
	}
}

void big_sort(t_stack **a, t_stack **b)
{
	int size;

	size = stack_size(*a);
	big_sort_to_b(a, b, size);
	big_sort_to_a(a, b);
}
