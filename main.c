/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalshbou <oalshbou@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 22:54:02 by oalshbou          #+#    #+#             */
/*   Updated: 2026/01/01 21:47:06 by oalshbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int size;

	if (argc < 2)
		return (0);
	a = fill_stack(argc,argv);
	if (!a)
	{
		write(2, "Error\n", 6);
		return(1);
	}
	b = NULL;
	size = stack_size(a);
	assign_index(a, size);
	if (size == 2)
		sa(&a);
	else if (size == 3)
		sort_three(&a);
	else if (size <= 5)
		sort_five(&a);
	else
		big_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
