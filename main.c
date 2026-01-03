/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalshbou <oalshbou@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 22:54:02 by oalshbou          #+#    #+#             */
/*   Updated: 2026/01/03 15:26:05 by oalshbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*fill_to_stack(int argc, char **argv)
{
	t_stack	*a;

	a = fill_stack(argc, argv);
	if (!a || check_dublicates(a))
	{
		write(2, "Error\n", 6);
		free_stack(&a);
		return (NULL);
	}
	assign_index(a);
	return (a);
}

static void	select_sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		big_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (argc < 2)
		return (0);
	a = fill_to_stack(argc, argv);
	if (!a)
		return (1);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	b = NULL;
	size = stack_size(a);
	select_sort(&a, &b, size);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
