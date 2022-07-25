/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_items_in_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:47:58 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/25 15:43:22 by tsharma          ###   ########.fr       */
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

void	small_mid_or_largest(t_array *a, t_array *b,
	t_array_item *smallest, t_array_item *largest)
{
	if (b->size == 1)
	{
		push_to_b(a, b);
		if (b->arr[0] < b->arr[1])
			swap_b(b->arr);
	}
	else
	{
		if (a->arr[0] > largest->number)
			bring_index_to_top_and_push(a, b, largest->index);
		else if (a->arr[0] < smallest->number)
		{
			bring_index_to_top_and_push(a, b, smallest->index);
			swap_b(b->arr);
		}
		else
			find_best_spot(a, b);
	}
}

void	calculate_smallest_and_largest(t_array *array,
	t_array_item *smallest, t_array_item *largest)
{
	int	i;

	i = 0;
	smallest->number = array->arr[0];
	smallest->index = 0;
	largest->number = array->arr[0];
	largest->index = 0;
	while (i < array->size)
	{
		if (array->arr[i] < smallest->number)
		{
			smallest->number = array->arr[i];
			smallest->index = i;
		}
		if (array->arr[i] > largest->number)
		{
			largest->number = array->arr[i];
			largest->index = i;
		}
		i++;
	}
}

/*	1. Find where the smallest and largest number are in the stack	*/
/*	2. See where the number you want to put, fits into the array	*/
/*	3. Calculate whether rotate or rev_rotate is the best			*/
void	take_best_path(t_array *a, t_array *b)
{
	t_array_item	smallest;
	t_array_item	largest;

	if (b->size == 0)
	{
		push_to_b(a, b);
		return ;
	}
	calculate_smallest_and_largest(b, &smallest, &largest);
	small_mid_or_largest(a, b, &smallest, &largest);
}

/*	Keep stack B in descending order								*/
/*	If item being pushed from A to B is not the largest number,		*/
/* 	find the right spot for it and keep pushing it into the stack	*/
/*	There are multiple ways to find the right spot					*/
/*	1. It is the smallest number, so push and rotate to bottom		*/
/*	2. It is the largest, so you push and keep it as is				*/
/*	3. It is somewhere in the middle, so you either rotate or 		*/
/*		rev_rotate depending on which is the shorter path			*/
void	push_items_in_b(t_array *a, t_array *b, t_array *subsqnc)
{
	int				i;
	int				a_size;
	t_array_item	smallest;
	t_array_item	largest;

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
	calculate_smallest_and_largest(b, &smallest, &largest);
	if ((largest.index + 1) <= (b->size) / 2)
		rotate_n_times(b, largest.index, 'b');
	else
		rev_rotate_n_times(b, b->size - largest.index, 'b');
}
