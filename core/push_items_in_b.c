/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_items_in_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:47:58 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/23 19:09:42 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_items_in_b(t_array *a, t_array *b, t_array *subsqnc)
{
	int	i;
	int	a_size;

	a_size = a->size;
	print_array(a->arr, a->size, "Pre A");
	print_array(subsqnc->arr, subsqnc->size, "LIS");
	i = 0;
	while (1)
	{
		if (array_contains(subsqnc, a->arr[0]))
			rotate_a(a);
		else
			push_to_b(a, b);
		// print_array(a->arr, a->size, "Iteration of A");
		// print_array(b->arr, b->size, "Iteration of B");
		i++;
		if (i == a_size)
			break ;
	}
	print_array(a->arr, a->size, "Post A");
	print_array(b->arr, b->size, "Post B");
}
