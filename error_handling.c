/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalshbou <oalshbou@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:09:48 by oalshbou          #+#    #+#             */
/*   Updated: 2026/01/02 19:39:08 by oalshbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
long ft_atoi_check(const char *str, int *e)
{
	long r;
	int sign;
	int i;

	r = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
	{
		*e = 1;
		return (0);
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			*e = 1;
			return (0);
		}
		r = (r * 10) + (str[i] - '0');
		if ((r * sign) > 2147483647 || (r * sign) < -2147483648)
		{
			*e = 1;
			return (0);
		}
		i++;
	}
	return (r * sign);
}

int check_dublicates(t_stack *a)
{
	t_stack *tmp;
while(a)
  {
	  tmp = a->next;
	  while(tmp)
	  {
		  if(a->value == tmp->value)
				 	 return(1);
				  tmp = tmp->next;
	  }
	  a = a->next;
  }
	return(0);	
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