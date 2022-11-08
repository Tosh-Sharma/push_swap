/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:25:16 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/08 18:25:45 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_array	*initialize_input(char **argv, int count);
t_array	*initialize_stack_b(t_array *a);
t_array	*check_for_different_style(char **argv);

// FOR 100 inputs
// ./push_swap `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`
// FOR 30 inputs
// ./push_swap `ruby -e "puts (-15..15).to_a.shuffle.join(' ')"`
// For the visualizer
// python3 pyviz.py `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`
// TODO: If subsqnc size = arr size, check if smallest element is first or not
// TODO: Take care of the problem of exit in case of
// implementation of circular linked list LIS detection.
int	main(int argc, char **argv)
{
	t_array	*a;
	t_array	*subsqnc;
	t_array	*b;

	if (argc == 1)
		exit(1);
	else
	{
		a = initialize_input(argv, argc - 1);
		if (a->size == 1)
			return (0);
		b = initialize_stack_b(a);
		if (a->size == 3)
			sort_three_numbers(a);
		else if (a->size == 5)
			sort_five_numbers(a, b);
		else
		{
			subsqnc = super_lis(a);
			sort_into_b(a, b, subsqnc);
			merge_stacks(a, b);
		}
	}
	return (0);
}

t_array	*initialize_input(char **argv, int count)
{
	int		i;
	int		j;
	int		*numbers;
	t_array	*a;

	i = 1;
	if (count == 1)
		return (check_for_different_style(argv));
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
	a = (t_array *)malloc(sizeof(t_array));
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
		free_array(a);
		exit(0);
	}
	b->size = 0;
	return (b);
}

t_array	*diffstyle_two(int *numbers, int count, char **input)
{
	t_array	*a;
	int		i;

	a = (t_array *)malloc(sizeof(t_array));
	a->size = count;
	a->arr = numbers;
	i = 0;
	while (input[i] != NULL)
	{
		free(input[i]);
		i++;
	}
	free(input);
	return (a);
}

t_array	*check_for_different_style(char **argv)
{
	char	**input;
	int		count;
	int		*numbers;
	int		i;
	int		j;

	input = ft_split(argv[1], ' ');
	init_numbers(&count, &i, &j);
	while (input[count] != NULL)
		count++;
	numbers = (int *)malloc(sizeof(int) * count);
	while (i < count)
	{
		numbers[i] = ft_superatoi(input[i], numbers);
		j = 0;
		while (j < i - 1)
		{
			if (numbers[j] == numbers[i - 1])
				exit_program(numbers);
			j++;
		}
		i++;
	}
	return (diffstyle_two(numbers, count, input));
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