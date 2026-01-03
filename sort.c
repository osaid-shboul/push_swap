/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalshbou <oalshbou@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:52:45 by oalshbou          #+#    #+#             */
/*   Updated: 2026/01/03 13:10:26 by oalshbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	f;
	int	s;
	int	t;

	f = (*stack_a)->index;
	s = (*stack_a)->next->index;
	t = (*stack_a)->next->next->index;
	if (f > s && s < t && f < t)
		sa(stack_a);
	else if (f > s && s > t)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (f > s && s < t && f > t)
		ra(stack_a);
	else if (f < s && s > t && f > t)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (f < s && s > t && f > t)
		rra(stack_a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	while (size > 3)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
		{
			pb(a, b);
			size--;
		}
		else
			ra(a);
	}
	sort_three(a);
	if ((*b)->next && (*b)->index < (*b)->next->index)
		sb(b);
	pa(a, b);
	pa(a, b);
}

void	big_sort_to_b(t_stack **a, t_stack **b, int size)
{
	int	i;
	int	range;

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

void	big_sort_to_a(t_stack **a, t_stack **b)
{
	int	max;
	int	pos;
	int	size;

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

void	big_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	big_sort_to_b(a, b, size);
	big_sort_to_a(a, b);
}
