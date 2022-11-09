/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_to_make.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:10:05 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/09 17:36:07 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_index_of_element(t_array *a, int element)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (element == a->arr[i])
			return (i);
		i++;
	}
	return (-1);
}

// 1. We have a set of elements to_move to be moved.
// 2. Check where is the closest element that needs to be moved from the array.
// 3. Go to element and eject into B.
// 4. Repeat until no elements left.
void	move_items_to_b(t_array *a, t_array *b, t_array *to_move)
{
	int		i;
	int		j;
	int		index;
	t_array	*indexes;

	j = 0;
	while (j < to_move->size)
	{
		i = 0;
		indexes = init_array(to_move->size, 1);
		while (i < to_move->size)
		{
			indexes->arr[i] = get_index_of_element(a, to_move->arr[i]);
			indexes->size++;
			i++;
		}
		index = find_cheapest_index(indexes, a->size);
		rotate_index_and_push_to_a(a, b, index, 0);
		take_best_path(a, b);
		free_array(indexes);
		j++;
	}
}
