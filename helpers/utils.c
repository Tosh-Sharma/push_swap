/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:04:46 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/14 18:04:52 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// TODO: Error goes on Standard Error (FD = 2 and not 1)
void	exit_program(int *a)
{
	free(a);
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

/*	If src array contains input element, return 1. */
/*	Else return 0. */
int	arr_cntns(t_array *src, int input)
{
	int	i;

	i = 0;
	while (i < src->size)
	{
		if (src->arr[i] == input)
			return (1);
		i++;
	}
	if (i == src->size)
		return (0);
	return (0);
}

int	array_contains_index(t_array *src, int input, int start, int end)
{
	int	i;

	i = start;
	while (i < end)
	{
		if (src->arr[i] == input)
			return (1);
		i++;
	}
	return (0);
}

// This function slices input array to create new array
// and includes the start and the end element.
t_array	*slice_array(t_array *input, int start, int end)
{
	t_array	*res;
	int		i;
	int		j;

	i = start;
	j = 0;
	res = (t_array *)malloc(sizeof(t_array));
	res->size = end - start + 1;
	res->arr = (int *)malloc(sizeof(int) * res->size);
	while (i <= end && i < input->size)
	{
		res->arr[j] = input->arr[i];
		i++;
		j++;
	}
	return (res);
}
