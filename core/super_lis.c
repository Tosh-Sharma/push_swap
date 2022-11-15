/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_lis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:57:57 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/15 19:40:04 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// There are n elements in the array
// Therefore, n lists possible
// Therefore n chances of finding the most LIS
// We iterate through each of them, to find the longest LIS
// And we pick the one with the largest list
t_array	*create_array_from_index(t_array *input, int index)
{
	t_array	*res;
	int		*array;
	int		i;
	int		j;

	res = (t_array *)malloc(sizeof(t_array));
	array = (int *)malloc(sizeof(int) * input->size);
	res->size = input->size;
	i = 0;
	j = 0;
	while (i < input->size)
	{
		if (index + i < input->size)
			array[i] = input->arr[index + i];
		else
		{
			array[i] = input->arr[j];
			j++;
		}
		i++;
	}
	res->arr = array;
	return (res);
}

// Free the memory allocated to the superset array and result_set
// and the elements within it.
void	free_everything(t_array **superset, t_array **result_set, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(superset[i]->arr);
		free(result_set[i]->arr);
		free(superset[i]);
		free(result_set[i]);
		i++;
	}
	free(superset);
	free(result_set);
}

t_array	*return_array_from_list(t_array **result_set, int size, int max_length)
{
	int		i;
	int		j;
	t_array	*result;

	i = 0;
	j = 0;
	result = (t_array *)malloc(sizeof(t_array));
	while (i < size)
	{
		if (result_set[i]->size == max_length)
		{
			result->size = max_length;
			result->arr = (int *)malloc(sizeof(int) * max_length);
			while (j < max_length)
			{
				result->arr[j] = result_set[i]->arr[j];
				j++;
			}
			break ;
		}
		i++;
	}
	return (result);
}

// Write the code for picking the longest subsequence
t_array	*pick_longest_sequence(t_array **result_set, int size)
{
	int		i;
	int		j;
	int		max_length;

	i = 0;
	j = 0;
	max_length = result_set[i]->size;
	while (i < size)
	{
		if (result_set[i]->size > max_length)
			max_length = result_set[i]->size;
		i++;
	}
	return (return_array_from_list(result_set, size, max_length));
}

t_array	*super_lis(t_array *a)
{
	t_array	**superset;
	t_array	**result_set;
	t_array	*subsqnc;
	int		i;

	superset = (t_array **)malloc(sizeof(t_array *) * a->size);
	result_set = (t_array **)malloc(sizeof(t_array *) * a->size);
	i = 0;
	while (i < a->size)
	{
		superset[i] = create_array_from_index(a, i);
		result_set[i] = fnd_lngst_sbsqnc(superset[i]);
		i++;
	}
	subsqnc = pick_longest_sequence(result_set, a->size);
	free_everything(superset, result_set, a->size);
	return (subsqnc);
}
