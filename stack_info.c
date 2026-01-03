/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalshbou <oalshbou@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:19:05 by oalshbou          #+#    #+#             */
/*   Updated: 2026/01/03 15:19:49 by oalshbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target_position(t_stack *stack, int target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == target)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

int	get_max_index(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	assign_index(t_stack *stack_a)
{
	t_stack	*p;
	t_stack	*cp;
	int		count;

	p = stack_a;
	while (p != NULL)
	{
		count = 0;
		cp = stack_a;
		while (cp != NULL)
		{
			if (cp->value < p->value)
				count++;
			cp = cp->next;
		}
		p->index = count;
		p = p->next;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*cur;

	if (!stack || !*stack)
		return ;
	cur = *stack;
	while (cur)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
	*stack = NULL;
}
