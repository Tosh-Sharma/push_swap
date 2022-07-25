/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:48:11 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/25 19:32:39 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_best_spot_2(t_array *a, t_array *b)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if ((i == (a->size - 1)) && ((b->arr[0] > a->arr[a->size - 1]
					&& (b->arr[0] < a->arr[0]))))
		{
			push_to_a(a, b);
			return ;
		}
		if (((b->arr[0] > a->arr[i] && (b->arr[0] < a->arr[i + 1]))))
		{
			rotate_index_and_push_to_a(a, b, i + 1);
			return ;
		}
		i++;
	}
}

void	merge_stacks(t_array *a, t_array *b)
{
	t_array_item	min;
	t_array_item	max;

	while (b->size != 0)
	{
		calculate_min_max(a, &min, &max);
		if (b->arr[0] > max.number)
			rotate_index_and_push_to_a(a, b, max.index);
		else if (b->arr[0] < min.number)
			rotate_index_and_push_to_a(a, b, min.index);
		else
			find_best_spot_2(a, b);
	}
	calculate_min_max(a, &min, &max);
	if ((min.index + 1) <= (a->size) / 2)
		rotate_n_times(a, min.index, 'a');
	else
		rev_rotate_n_times(a, a->size - min.index, 'a');
}
