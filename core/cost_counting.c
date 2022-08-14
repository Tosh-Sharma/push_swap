/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_counting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:37:24 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/14 23:39:55 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_array	*get_count_of_elements(t_array *input, t_array *first,
		t_array *last, int percent)
{
	t_array		*first_set;
	t_array		*last_set;
	int			i;
	int			counter;

	first_set = init_array(input->size, 1);
	last_set = init_array(input->size, 1);
	i = 0;
	counter = 0;
	while (i < (input->size * percent / 100))
	{
		if (arr_cntns(first, input->arr[i]) || arr_cntns(last, input->arr[i]))
		{
			first_set->arr[counter] = input->arr[i];
			first_set->size++;
			counter++;
		}
		i++;
	}
	counter = 0;
	i = input->size - (input->size * percent / 100) - 1;
	while (i < input->size)
	{
		if (arr_cntns(first, input->arr[i]) || arr_cntns(last, input->arr[i]))
		{
			last_set->arr[counter] = input->arr[i];
			last_set->size++;
			counter++;
		}
		i++;
	}
	if (last_set->size > first_set->size)
	{
		rev_array(last_set);
		return (last_set);
	}
	return (first_set);
}

// Get first 20% of sorted input and detect matches in
// first and last 20% of input.
// Get last 20% of sorted input and detect matches in
// first and last 20% of input.
// Return the elements found.
t_array	*element_count(t_array *input, t_array *sorted_input, int percent)
{
	t_array	*first;
	t_array	*last;
	t_array	*res;

	first = slice_array(sorted_input, 0,
			sorted_input->size * percent / 100);
	print_array(first->arr, first->size, "first section");
	last = slice_array(sorted_input,
			sorted_input->size - 1 - (sorted_input->size * percent / 100),
			sorted_input->size - 1);
	print_array(last->arr, last->size, "last section");
	res = get_count_of_elements(input, first, last, percent);
	free(first->arr);
	free(last->arr);
	free(first);
	free(last);
	return (res);
}
