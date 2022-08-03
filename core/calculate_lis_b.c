/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_lis_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:03:05 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/03 17:18:38 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_array	*calculate_lis_b(t_array *a, t_array *subsqnc)
{
	t_array	*lis_b;
	t_array	b;
	int		i;
	int		j;

	b.size = a->size - subsqnc->size;
	b.arr = (int *)malloc(sizeof(int) * b.size);
	i = 0;
	j = 0;
	while (i < a->size)
	{
		if (!array_contains(subsqnc, a->arr[i]))
		{
			b.arr[j] = a->arr[i];
			j++;
		}
		i++;
	}
	lis_b = super_lis(&b);
	free(b.arr);
	return (lis_b);
}
