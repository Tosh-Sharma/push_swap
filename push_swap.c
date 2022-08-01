/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:25:16 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/01 21:19:09 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_array	*initialize_input(char **argv, int count);
t_array	*initialize_stack_b(t_array *a);

// ./push_swap 3 18 4 13 12 -2 -16 0 -1 -3 7 8 -18 20 -17 6 10 11
// -14 -7 -11 -13 -19 -6 5 -5 14 -12 1 9 16 -4 -20 19 -10 2 -8 17 -15 15 -9
//	Redoing the algorithm
// 1. Detect LIS.
// 2. Detect LIS 2 from the subset of LIS 1.
// 3. Sort the array and store the result in sorted_array
// 4. Split input_array into 2 parts and put elements closest to true index.
// i.e. Stack A contains 0 to n/2 elements in DESC order and
// 		stack B contains n/2 to n elements in ASC order
// Elements get
// A. Either popped to stack_B and they either stay or rotate
// B. Swap into stack_A or rotate.
// TODO: If subsqnc->size == a->size, do nothing
// TODO: Check if smallest element is the first element or not
// TODO: Take care of the problem of exit in case of
// implementation of circular linked list LIS detection.
int	main(int argc, char **argv)
{
	t_array	*a;
	t_array	*subsqnc;
	t_array	*b;

	a = initialize_input(argv, argc - 1);
	print_array(a->arr, a->size, "A");
	b = initialize_stack_b(a);
	subsqnc = super_lis(a);
	print_array(subsqnc->arr, subsqnc->size, "LIS");
	if (subsqnc->size == a->size)
		exit(0);
	push_items_in_b(a, b, subsqnc);
	print_array(a->arr, a->size, "Mid A");
	print_array(b->arr, b->size, "Mid B");
	merge_stacks(a, b);
	print_array(a->arr, a->size, "Final A");
	free(a->arr);
	free(b->arr);
	free(a);
	free(b);
	free(subsqnc->arr);
	free(subsqnc);
	return (0);
}

// TODO: Handle inputs in the second style
// Everything is in one single string and you need
// to use ft_split on the code.
t_array	*initialize_input(char **argv, int count)
{
	int		i;
	int		j;
	int		*numbers;
	t_array	*a;

	i = 1;
	a = (t_array *)malloc(sizeof(t_array));
	numbers = (int *)malloc(sizeof(int) * count);
	while (i <= count)
	{
		numbers[i - 1] = ft_superatoi(argv[i], numbers);
		j = 0;
		while (j < i - 1)
		{
			if (numbers[j] == numbers[i - 1])
				exit_program(numbers);
			j++;
		}
		i++;
	}
	a->arr = numbers;
	a->size = count;
	return (a);
}

t_array	*initialize_stack_b(t_array *a)
{
	t_array	*b;

	b = (t_array *)malloc(sizeof(t_array));
	b->arr = (int *)malloc(sizeof(int) * a->size);
	if (!b->arr)
	{
		free(a->arr);
		free(a);
		exit(0);
	}
	b->size = 0;
	return (b);
}
