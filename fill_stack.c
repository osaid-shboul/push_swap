/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalshbou <oalshbou@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 23:48:01 by oalshbou          #+#    #+#             */
/*   Updated: 2026/01/02 18:07:04 by oalshbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_s(char **str)
{
	int	i;

	i = 0;
	while(str[i])
			free(str[i++]);
		free(str);
}

t_stack *fill_stack(int argc, char **argv)
{
	t_stack *a;
	char	**temp;
	int i;
	int j;	
	int error;
	long	num;
	
	a = NULL;
	i = 1;
	while (i < argc)
	{
		temp = ft_split(argv[i], ' ');
		j = 0;
		while (temp[j])
		{
			error = 0;
			num = ft_atoi_check(temp[j], &error);
			if (error == 1)
			{
				free_stack(&a);
				free_s(temp);
				return(NULL);
			}
			add_last(&a, ft_stack_new((int)num));
			j++;
		}
		free_s(temp);
		i++;
	}
	return (a);
}
