/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:50:44 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/07 19:48:43 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_array	*init_array(int size, int reset_size)
{
	t_array	*res;

	res = (t_array *)malloc(sizeof(t_array));
	if (reset_size == 1)
		res->size = 0;
	else
		res->size = size;
	res->arr = (int *)malloc(sizeof(int) * size);
	return (res);
}

void	free_array(t_array *arr)
{
	free(arr->arr);
	free(arr);
}

void	init_numbers(int *count, int *i, int *j)
{
	*count = 0;
	*i = 0;
	*j = 0;
}
