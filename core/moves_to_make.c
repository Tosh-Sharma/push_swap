/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_to_make.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:10:05 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/15 19:47:10 by tsharma          ###   ########.fr       */
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
			break ;
		i++;
	}
	return (i);
}

// Go towards each of the elements in the to_move array
// Move them to array B correctly.
void	move_items_to_b(t_array *a, t_array *b, t_array *to_move,
		t_array *subsqnc)
{
	int	i;
	int	index;

	(void)subsqnc;
	i = 0;
	while (i < to_move->size)
	{
		index = get_index_of_element(a, to_move->arr[i]);
		rotate_index_and_push_to_a(a, b, index, 0);
		take_best_path(a, b);
		i++;
	}
}
