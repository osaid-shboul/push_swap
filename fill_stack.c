/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalshbou <oalshbou@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 23:48:01 by oalshbou          #+#    #+#             */
/*   Updated: 2026/01/03 14:22:42 by oalshbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_s(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

static int	split_el(t_stack **a, char **temp)
{
	int		j;
	int		error;
	long	num;

	j = 0;
	while (temp[j])
	{
		error = 0;
		num = ft_atoi_check(temp[j], &error);
		if (error == 1)
		{
			free_stack(a);
			free_s(temp);
			return (0);
		}
		add_last(a, ft_stack_new((int)num));
		j++;
	}
	return (1);
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*a;
	char	**temp;
	int		i;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		temp = ft_split(argv[i], ' ');
		if (!temp)
			return (NULL);
		if (!split_el(&a, temp))
			return (NULL);
		free_s(temp);
		i++;
	}
	return (a);
}
