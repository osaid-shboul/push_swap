/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalshbou <oalshbou@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:19:00 by oalshbou          #+#    #+#             */
/*   Updated: 2025/12/31 00:45:28 by oalshbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_stack_new(int value)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void free_stack(t_stack **stack)
{
	t_stack *temp;
	t_stack *cur;

	if (!stack || !*stack)
		return;
	cur = *stack;
	while (cur)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
	*stack = NULL;
}
void assign_index(t_stack *stack_a, int stack_size)
{
	t_stack *p;
	t_stack *cp;
	int count;

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
int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while(stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
t_stack *find_lastn(t_stack *stack)
{
	if(!stack)
		return(NULL);
	while(stack->next != NULL)
		stack = stack->next;
	return (stack);
}
void	add_last(t_stack **stack, t_stack *temp)
{
	t_stack *last;

	if(*stack == NULL)
	{
		*stack = temp;
		return;
	}
	last = find_lastn(*stack);
	last->next = temp;
}
