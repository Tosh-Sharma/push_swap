/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:12:30 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/08 20:16:14 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_index_closer_to_zero(int index1, int index2, int size)
{
	int	distance_to_zero_1;
	int	distance_to_zero_2;

	if (index1 > size / 2)
		distance_to_zero_1 = size - 1 - index1;
	else
		distance_to_zero_1 = index1;
	if (index2 > size / 2)
		distance_to_zero_2 = size - 1 - index2;
	else
		distance_to_zero_2 = index2;
	if (distance_to_zero_1 > distance_to_zero_2)
		return (index1);
	return (index2);
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
	while (i < a->size)
	{
		if (a->arr[i] < max && a->arr[i] > second_max)
			second_max = a->arr[i];
		i++;
	}
	numbers[0] = max;
	numbers[1] = second_max;
}

void	sort_five_numbers(t_array *a, t_array *b)
{
	int	numbers[2];

	find_largest_two_numbers(a, numbers);
	if (find_index_closer_to_zero(find_index(a, numbers[0]),
			find_index(a, numbers[1]), a->size) == find_index(a, numbers[0]))
	{
		bring_index_to_top_and_push(a, b, find_index(a, numbers[0]));
		bring_index_to_top_and_push(a, b, find_index(a, numbers[1]));
	}
	else
	{
		bring_index_to_top_and_push(a, b, find_index(a, numbers[1]));
		bring_index_to_top_and_push(a, b, find_index(a, numbers[0]));
	}
	sort_three_numbers(a->arr);
	if (b->arr[1] > b->arr[0])
		swap_b(b->arr);
	push_to_a(a, b);
	push_to_a(a, b);
	rotate_a(a);
	rotate_a(a);
}
