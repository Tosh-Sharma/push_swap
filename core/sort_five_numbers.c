/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:12:30 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/09 15:51:03 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_index_closer_to_zero(int index1, int index2, int size)
{
	int	distance_to_zero_1;
	int	distance_to_zero_2;

	if (index1 > size / 2)
		distance_to_zero_1 = size - index1;
	else
		distance_to_zero_1 = index1;
	if (index2 > size / 2)
		distance_to_zero_2 = size - index2;
	else
		distance_to_zero_2 = index2;
	if (distance_to_zero_1 > distance_to_zero_2)
		return (index2);
	return (index1);
}

int	find_index(t_array *a, int number)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->arr[i] == number)
			break ;
		i++;
	}
	return (i);
}

void	find_largest_two_numbers(t_array *a, int *numbers)
{
	int	i;
	int	max;
	int	second_max;

	i = 1;
	max = a->arr[0];
	second_max = a->arr[0];
	while (i < a->size)
	{
		if (a->arr[i] > max)
			max = a->arr[i];
		i++;
	}
	i = 1;
	if (second_max == max)
		second_max = a->arr[1];
	while (i < a->size)
	{
		if (a->arr[i] < max && a->arr[i] > second_max)
			second_max = a->arr[i];
		i++;
	}
	numbers[0] = max;
	numbers[1] = second_max;
}

void	bring_to_top_n_push_to_b(t_array *a, t_array *b,
	int index)
{
	if ((index + 1) <= (a->size / 2))
		rotate_n_times(a, index, 'a');
	else
		rev_rotate_n_times(a, a->size - index, 'a');
	push_to_b(a, b);
}

void	sort_five_numbers(t_array *a, t_array *b)
{
	int	numbers[2];

	find_largest_two_numbers(a, numbers);
	if (find_index_closer_to_zero(find_index(a, numbers[0]),
			find_index(a, numbers[1]), a->size) == find_index(a, numbers[0]))
	{
		bring_to_top_n_push_to_b(a, b, find_index(a, numbers[0]));
		bring_to_top_n_push_to_b(a, b, find_index(a, numbers[1]));
	}
	else
	{
		bring_to_top_n_push_to_b(a, b, find_index(a, numbers[1]));
		bring_to_top_n_push_to_b(a, b, find_index(a, numbers[0]));
	}
	sort_three_numbers(a);
	if (b->arr[1] > b->arr[0])
		swap_b(b->arr);
	push_to_a(a, b);
	push_to_a(a, b);
	rotate_a(a);
	rotate_a(a);
}
