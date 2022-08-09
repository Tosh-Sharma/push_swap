/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_filter_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:37:24 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/09 17:22:00 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Get first 20% of src and detect matches in
// first and last 20% of input.
// Get last 20% of src and detect matches in
// last and last 20% of input.
// Compare where more elements were found.
// Go in that direction.
// First mini array contains first half of the elements.
// Now we look for sorted elements in input's first half and last half.
void	element_count(t_array *input, t_array *src, int percent)
{
	t_array	mini_arr;

	mini_arr.size = percent * src->size / 100;
	mini_arr.arr = (int *)malloc(sizeof(int) * mini_arr.size);
	mini_arr.arr = ft_cpyarray(mini_arr.arr, src, mini_arr.size);
}
