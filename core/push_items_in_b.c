/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_items_in_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:47:58 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/15 19:47:26 by tsharma          ###   ########.fr       */
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

//	Algorithm to sort data into B in the most efficient manner
//	1. m = n - l1
//	2. sorted_m = sorted "m"
//	3. Calculate most of first/last 20% of s_m in first/last 20% of m.
//	4. Pick whichever one wins.
//	5. Keep refining the process of picking and their cost involved.
//	6. Like you can add cost of moving into B and out of A.
//	7. You can track for both bottom half and upper half of s_m elements.
void	sort_into_b(t_array *a, t_array *b, t_array *subsqnc,
		int counter)
{
	t_array		*m;
	t_array		*sorted_m;
	t_array		*items_to_move;
	int			percent;

	m = calculate_m(a, subsqnc);
	if (m->size == 0)
		return ;
	sorted_m = copy_and_sort(m);
	percent = calculate_percent(a, b, subsqnc, counter);
	items_to_move = element_count(m, sorted_m, percent);
	move_items_to_b(a, b, items_to_move, subsqnc);
	free(items_to_move->arr);
	free(items_to_move);
	free(m->arr);
	free(m);
	free(sorted_m->arr);
	free(sorted_m);
}
