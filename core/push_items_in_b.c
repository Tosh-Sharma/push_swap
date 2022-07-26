/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_items_in_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:47:58 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/26 17:38:58 by tsharma          ###   ########.fr       */
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
			&& ((b->arr[b->size - 1] > a->arr[0])
				&& (b->arr[0] < a->arr[0])))
		{
			push_to_b(a, b);
			return ;
		}
		if ((b->arr[i] > a->arr[0]) && (b->arr[i + 1] < a->arr[0]))
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
			bring_index_to_top_and_push(a, b, max->index);
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

//	Keep stack B in descending order
//	If item being pushed from A to B is not the max number,
// 	find the right spot for it and keep pushing it into the stack
//	There are multiple ways to find the right spot
//	1. It is the min number, so push and rotate to bottom
//	2. It is the max, so you push and keep it as is
//	3. It is somewhere in the middle, so you either rotate or
//		rev_rotate depending on which is the shorter path
//	TODO: Can you optimise the code here by either
//	 eliminating the need to sort it in order or nah?
void	push_items_in_b(t_array *a, t_array *b, t_array *subsqnc)
{
	int				i;
	int				a_size;
	t_array_item	min;
	t_array_item	max;

	a_size = a->size;
	i = 0;
	while (1)
	{
		if (array_contains(subsqnc, a->arr[0]))
			rotate_a(a);
		else
			take_best_path(a, b);
		i++;
		if (i == a_size)
			break ;
	}
	calculate_min_max(b, &min, &max);
}
