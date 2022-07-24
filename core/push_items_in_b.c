/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_items_in_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:47:58 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/24 15:42:05 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	calculate_smallest_and_largest(t_array *b,
	t_array_item *smallest, t_array_item *largest)
{
	int	i;

	i = 0;
	smallest->number = b->arr[0];
	smallest->index = 0;
	largest->number = b->arr[0];
	largest->index = 0;
	while (i < b->size)
	{
		if (b->arr[i] < smallest->number)
		{
			smallest->number = b->arr[i];
			smallest->index = i;
		}
		if (b->arr[i] > largest->number)
		{
			largest->number = b->arr[i];
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
	int	i;
	int	a_size;

	a_size = a->size;
	print_array(a->arr, a->size, "Pre A");
	print_array(subsqnc->arr, subsqnc->size, "LIS");
	i = 0;
	while (1)
	{
		if (array_contains(subsqnc, a->arr[0]))
			rotate_a(a);
		else
			take_best_path(a, b);
		// print_array(a->arr, a->size, "Iteration of A");
		// print_array(b->arr, b->size, "Iteration of B");
		i++;
		if (i == a_size)
			break ;
	}
	print_array(a->arr, a->size, "Post A");
	print_array(b->arr, b->size, "Post B");
}
