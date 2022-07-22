/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:57:41 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/22 18:52:18 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Shift down all elements of stack by one */
/* The last element becomes the first one. */
void	rev_rotate_array(int *array, int size)
{
	int	i;
	int	temp;

	temp = array[size - 1];
	i = size - 1;
	while (i > 0)
	{
		array[i] = array[i - 1];
		i--;
	}
	array[0] = temp;
}

void	rev_rotate_a(int *a, int size)
{
	rev_rotate_array(a, size);
	ft_putstr_fd("rra\n", 1);
}

void	rev_rotate_b(int *b, int size)
{
	rev_rotate_array(b, size);
	ft_putstr_fd("rrb\n", 1);
}

void	rev_rotate_both(int *a, int size_a, int *b, int size_b)
{
	rev_rotate_array(a, size_a);
	rev_rotate_array(b, size_b);
	ft_putstr_fd("rrr\n", 1);
}
