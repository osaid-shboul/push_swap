/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalshbou <oalshbou@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 23:48:01 by oalshbou          #+#    #+#             */
/*   Updated: 2025/12/31 00:06:48 by oalshbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *fill_stack(int argc, char **argv)
{
	t_stack *a;
	long num;
	int error;
	int i;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		error = 0;
		num = ft_atoi_check(argv[i], &error);
		if (error == 1)
		{
			free_stack(&a);
			return (NULL);
		}
		add_back(&a, ft_stack_new((int)num));
		i++;
	}
	return (a);
}
