/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_to_make.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:10:05 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/18 18:11:30 by tsharma          ###   ########.fr       */
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

// We have a set of elements to_move to be moved.
// We need to move every element we encounter over to B
// Else keep rotating as usual.
// Can do cost analysis to improve the cost to move everything.
void	move_items_to_b(t_array *a, t_array *b, t_array *to_move)
{
	int	i;

	i = 0;
	while (i < to_move->size)
	{
		if (arr_cntns(to_move, a->arr[0]))
		{
			take_best_path(a, b);
			i++;
		}
		else
			rotate_a(a);
	}
}
