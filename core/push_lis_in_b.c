/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lis_in_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:47:28 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/03 18:03:03 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_lis_in_b(t_array *a, t_array *b, t_array *lis_b)
{
	int	i;

	i = 0;
	while (i <= a->size)
	{
		if (array_contains(lis_b, a->arr[0]))
			push_to_b(a, b);
		else
			rotate_a(a);
		i++;
	}
	print_array(a->arr, a->size, "A");
	print_array(lis_b->arr, lis_b->size, "lis_b");
	print_array(b->arr, b->size, "B");
}
