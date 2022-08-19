/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:17:31 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/19 18:19:17 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_smallest_element(t_array *costs)
{
	int	min_index;
	int	i;

	i = 1;
	min_index = 0;
	while (i < costs->size)
	{
		if (costs->arr[i] < costs->arr[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}
