/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalshbou <oalshbou@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:19:00 by oalshbou          #+#    #+#             */
/*   Updated: 2026/01/02 18:31:52 by oalshbou         ###   ########.fr       */
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

void assign_index(t_stack *stack_a)
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

int stack_size(t_stack *stack)
{
	int count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
t_stack *find_lastn(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void add_last(t_stack **stack, t_stack *temp)
{
	t_stack *last;

	if (*stack == NULL)
	{
		*stack = temp;
		return;
	}
	last = find_lastn(*stack);
	last->next = temp;
}

int get_max_index(t_stack *stack)
{
	int max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int get_target_position(t_stack *stack, int target)
{
	int pos;

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

int ft_strlen(const char *s)
{
    int i = 0;
    while (s[i]) i++;
    return (i);
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}


static char	*word_dup(char const *s, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**result;

	if (!s)
		return (NULL);
	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= (size_t)ft_strlen(s)) 
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == (size_t)ft_strlen(s)) && index >= 0)
		{
			result[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}
