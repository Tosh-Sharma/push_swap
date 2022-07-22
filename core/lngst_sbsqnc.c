/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lngst_sbsqnc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:34:17 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/22 21:54:10 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// #include <stdio.h>

int	ceil_index(int *input, int *temp, int end, int s)
{
	int	start;
	int	middle;
	int	len;

	len = end;
	start = 0;
	while (start <= end)
	{
		middle = (start + end) / 2;
		if (middle < len && input[temp[middle]] < s
			&& s <= input[temp[middle + 1]])
			return (middle + 1);
		else if (input[temp[middle]] < s)
			start = middle + 1;
		else
			end = middle - 1;
	}
	return (-1);
}

int	traverse_array(int *numbers, int *res, int *temp, int size)
{
	int	len;
	int	index;
	int	i;

	i = 1;
	len = 0;
	while (i < size)
	{
		if (numbers[temp[0]] > numbers[i])
			temp[0] = i;
		else if (numbers[temp[len]] < numbers[i])
		{
			len++;
			temp[len] = i;
			res[temp[len]] = temp[len - 1];
		}
		else
		{
			index = ceil_index(numbers, temp, len, numbers[i]);
			temp[index] = i;
			res[temp[index]] = temp[index - 1];
		}
		i++;
	}
	return (len);
}

// Length of LIS array in below function is len + 1.
t_array	*get_subsqnc(int *res, int *numbers, int len, int index)
{
	int		*output;
	int		i;
	t_array	*subsqnc;

	i = len;
	output = (int *)malloc(sizeof(int) * (len + 1));
	while (index != -1)
	{
		output[i] = numbers[index];
		index = res[index];
		i--;
	}
	free(res);
	subsqnc = (t_array *)malloc(sizeof(t_array));
	subsqnc->arr = output;
	subsqnc->size = len + 1;
	return (subsqnc);
}

t_array	*fnd_lngst_sbsqnc(t_array *a)
{
	int	*temp;
	int	*res;
	int	i;
	int	len;
	int	index;

	i = 0;
	res = (int *)malloc(sizeof(int) * a->size);
	temp = (int *)malloc(sizeof(int) * a->size);
	while (i < a->size)
	{
		res[i] = -1;
		i++;
	}
	temp[0] = 0;
	len = traverse_array(a->arr, res, temp, a->size);
	index = temp[len];
	free(temp);
	return (get_subsqnc(res, a->arr, len, index));
}

// int	main(void)
// {
// 	int	numbers[11] = { 3, 4, -1, 5, 8, 2, 3, 12, 7, 9, 10};
// 	int	i;
// 	int	arr_size;

// 	i = 0;
// 	printf("The unsorted numbers are as below\n");
// 	while (i < 11)
// 	{
// 		printf("%d ", numbers[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	fnd_lngst_sbsqnc(numbers, 11);
// 	system("leaks a.out");
// 	return (0);
// }
