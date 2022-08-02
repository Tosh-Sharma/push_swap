/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:13:32 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/03 00:06:50 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>
#include "../push_swap.h"

typedef struct ijk
{
	int	i;
	int	j;
	int	k;
}	t_ijk;

void	free_memory(t_array *left, t_array *right, t_ijk *ijk)
{
	free(left->arr);
	free(right->arr);
	free(left);
	free(right);
	free(ijk);
}

t_array	*allocate_and_assign(int size, int *arr, int index)
{
	t_array	*array;
	int		i;

	i = 0;
	array = (t_array *)malloc(sizeof(t_array));
	array->size = size;
	array->arr = (int *)malloc(sizeof(int) * size);
	while (i < array->size)
	{
		array->arr[i] = arr[index + i];
		i++;
	}
	return (array);
}

t_ijk	*sort_data(t_array *left, t_array *right, int *arr, int l)
{
	t_ijk	*ijk;

	ijk = (t_ijk *)malloc(sizeof(t_ijk));
	ijk->i = 0;
	ijk->j = 0;
	ijk->k = l;
	while (ijk->i < left->size && ijk->j < right->size)
	{
		if (left->arr[ijk->i] <= right->arr[ijk->j])
		{
			arr[ijk->k] = left->arr[ijk->i];
			ijk->i++;
		}
		else
		{
			arr[ijk->k] = right->arr[ijk->j];
			ijk->j++;
		}
		ijk->k++;
	}
	return (ijk);
}

void	merge(int arr[], int l, int m, int r)
{
	t_ijk	*ijk;
	t_array	*left;
	t_array	*right;

	left = allocate_and_assign(m - l + 1, arr, l);
	right = allocate_and_assign(r - m, arr, m + 1);
	ijk = sort_data(left, right, arr, l);
	while (ijk->i < left->size)
	{
		arr[ijk->k] = left->arr[ijk->i];
		ijk->i++;
		ijk->k++;
	}
	while (ijk->j < right->size)
	{
		arr[ijk->k] = right->arr[ijk->j];
		ijk->j++;
		ijk->k++;
	}
	free_memory(left, right, ijk);
}

void	merge_sort(int arr[], int l, int r)
{
	int	m;

	if (l < r)
	{
		m = l + (r - l) / 2;
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

// /* Driver code */
// int	main(void)
// {
// 	t_array	arr;
// 	int		array[] = {12, 11, 13, 5, 6, 7, -1, 0, 4};

// 	arr.arr = array;
// 	arr.size = 9;
// 	printf("Given array is \n");
// 	print_array(arr.arr, arr.size, "Pre Array");
// 	merge_sort(arr.arr, 0, arr.size - 1);
// 	printf("\nSorted array is \n");
// 	print_array(arr.arr, arr.size, "Post array");
// 	return (0);
// }
