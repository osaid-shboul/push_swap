/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalshbou <oalshbou@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:09:48 by oalshbou          #+#    #+#             */
/*   Updated: 2026/01/03 15:16:30 by oalshbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static int	check_overflow(long res, int sign, int *e)
{
	if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
	{
		*e = 1;
		return (1);
	}
	return (0);
}

long	ft_atoi_check(const char *str, int *e)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	i = 0;
	sign = handle_sign(str, &i);
	if (str[i] == '\0')
		return (*e = 1, 0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			*e = 1;
			return (0);
		}
		res = (res * 10) + (str[i] - '0');
		if (check_overflow(res, sign, e))
			return (0);
		i++;
	}
	return (res * sign);
}

int	check_dublicates(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
