/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_items_in_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:47:58 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/17 22:08:23 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_best_spot(t_array *a, t_array *b)
{
	int	i;

	i = 0;
	while (i < b->size)
	{
		if ((i == (b->size - 1))
			&& (((b->arr[b->size - 1] > a->arr[0])
					&& (b->arr[0] < a->arr[0]))
				|| ((b->arr[b->size - 1] < a->arr[0])
					&& (b->arr[0] > a->arr[0]))))
		{
			push_to_b(a, b);
			return ;
		}
		if ((b->arr[i] < a->arr[0]) && (b->arr[i + 1] > a->arr[0]))
		{
			bring_index_to_top_and_push(a, b, i + 1);
			return ;
		}
		i++;
	}
}

void	place_in_position(t_array *a, t_array *b,
	t_array_item *min, t_array_item *max)
{
	if (b->size == 1)
	{
		push_to_b(a, b);
		if (b->arr[0] < b->arr[1])
			swap_b(b->arr);
	}
	else
	{
		if (a->arr[0] > max->number)
			bring_highest_to_bottom_and_push(a, b, max->index);
		else if (a->arr[0] < min->number)
			bring_index_to_bottom_and_push(a, b, min->index);
		else
			find_best_spot(a, b);
	}
}

void	calculate_min_max(t_array *array,
	t_array_item *min, t_array_item *max)
{
	int	i;

	i = 0;
	min->number = array->arr[0];
	min->index = 0;
	max->number = array->arr[0];
	max->index = 0;
	while (i < array->size)
	{
		if (array->arr[i] < min->number)
		{
			min->number = array->arr[i];
			min->index = i;
		}
		if (array->arr[i] > max->number)
		{
			max->number = array->arr[i];
			max->index = i;
		}
		i++;
	}
}

//	1. Find where the min and max number are in the stack
//	2. See where the number you want to put, fits into the array
//	3. Calculate whether rotate or rev_rotate is the best
void	take_best_path(t_array *a, t_array *b)
{
	t_array_item	min;
	t_array_item	max;

	if (b->size == 0)
	{
		push_to_b(a, b);
		return ;
	}
	calculate_min_max(b, &min, &max);
	place_in_position(a, b, &min, &max);
}
