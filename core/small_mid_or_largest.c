/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_mid_or_largest.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:01:47 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/24 16:52:17 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bring_index_to_top_and_push(t_array *a, t_array *b,
	int index)
{
	if ((index + 1) <= (b->size) / 2)
	{
	}
}

void	find_best_spot(t_array *a, t_array *b,
	t_array_item *smallest, t_array_item *largest)
{
}

void	small_mid_or_largest(t_array *a, t_array *b,
	t_array_item *smallest, t_array_item *largest)
{
	if (a->arr[0] < smallest->number)
	{
		bring_index_to_top_and_push(a, b, smallest->index);
		return ;
	}
	else if (a->arr[0] > largest->number)
	{
		bring_index_to_top_and_push(a, b, largest->index);
		return ;
	}
	else
		find_best_spot(a, b, smallest, largest);
}
