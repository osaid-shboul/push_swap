/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalshbou <oalshbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:52:45 by oalshbou          #+#    #+#             */
/*   Updated: 2026/01/01 22:17:31 by oalshbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <push_swap.h>

void	sort_three(t_stack **stack_a)
{
	int	f;
	int	s;
	int	t;

	f = (*stack_a)->index;
	s = (*stack_a)->next->index;
	t = (*stack_a)->next->next->index;
	if(f > s && s < t && f < t)
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
		sa(stacck_a);
		ra(stack_a);
	}
	else if ( f < s && s > t && f > t)
		rra(stack_a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	while(size > 3)
	{
		if((*a)->index == 0 || (*a)->index == 1)
		{
			pb(a,b);
			size--;
		}
		else
			ra(a);
	}
	sort_three(a);
	if((*b)->next && (*b)->index < (*b)->next->index)
		sb(b);
	pa(a,b);
	pa(a,b);
}

