/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:25:16 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/03 18:56:26 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_array	*initialize_input(char **argv, int count);
t_array	*initialize_stack_b(t_array *a);
void	calculate_swap_improvements(t_array *a);
// FOR 100 inputs
// ./push_swap `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`
// FOR 30 inputs
// ./push_swap `ruby -e "puts (-15..15).to_a.shuffle.join(' ')"`
// python3 pyviz.py `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`
// TODO: If subsqnc size = arr size, check if smallest element is first or not
// TODO: Take care of the problem of exit in case of
// implementation of circular linked list LIS detection.
int	main(int argc, char **argv)
{
	t_array	*a;
	t_array	*subsqnc;
	t_array	*b;
	t_array	*lis_b;
	int		i;

	a = initialize_input(argv, argc - 1);
	b = initialize_stack_b(a);
	i = 1;
	print_array(a->arr, a->size, "A");
	calculate_swap_improvements(a);
	while (1)
	{
		subsqnc = super_lis(a);
		printf("Iteration number: %d\n", i++);
		print_array(a->arr, a->size, "A");
		print_array(subsqnc->arr, subsqnc->size, "LIS A");
		if (subsqnc->size == a->size)
			break ;
		lis_b = calculate_lis_b(a, subsqnc);
		push_lis_in_b(a, b, lis_b);
		free(subsqnc->arr);
		free(subsqnc);
		free(lis_b->arr);
		free(lis_b);
	}
	merge_stacks(a, b);
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

void	calculate_swap_improvements(t_array *a)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < a->size)
	{
		if (i == a->size - 1)
		{
			if (a->arr[a->size - 1] > a->arr[0])
				count++;
		}
		else if (a->arr[i] > a->arr[i + 1])
			count++;
		i++;
	}
	printf("Swap improvements possible are %d\n", count);
}
// Other logics to consider.
// 1. Let sample set be n. Detect LIS 'l1' in 'n'.
// 2. Sort elements 'm' (n - l1) to get 'sorted_b'.
// 3. Insert elements of 'm' into stack B closest to 'sorted_b'.
// 4. Split 'm' into 2 parts and put items closest to 'sorted_b'.
// i.e. Stack A contains 0 to n/2 elements in DESC order
// 		stack B contains n/2 + 1 to n'th element in ASC order
// Elements get
// A. Either popped to stack_B and they either stay or rotate
// B. Swap into stack_A or rotate.