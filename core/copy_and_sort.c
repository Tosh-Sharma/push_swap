/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_and_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:48:36 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/04 18:48:49 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_array	*copy_and_sort(t_array *array)
{
	t_array	*sorted_array;

	sorted_array = (t_array *)malloc(sizeof(t_array));
	sorted_array->size = array->size;
	sorted_array->arr = (int *)malloc(sizeof(int) * sorted_array->size);
	ft_cpyarray(sorted_array->arr, array->arr, (size_t)array->size);
	merge_sort(sorted_array->arr, 0, sorted_array->size - 1);
	return (sorted_array);
}
