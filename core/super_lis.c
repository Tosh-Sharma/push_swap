/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_lis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:57:57 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/26 18:15:18 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

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
		i++;
	}
	free(superset);
	free(result_set);
}

// Write the code for picking the longest subsequence
t_array	*pick_longest_sequence(t_array **result_set, int size)
{
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
		printf("Result_set at index %d gave length %d\n",
			i, result_set[i]->size);
		i++;
	}
	subsqnc = pick_longest_sequence(result_set, a->size);
	free_everything(superset, result_set, a->size);
	return (subsqnc);
}
