/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:25:16 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/25 15:32:24 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_array	*initialize_input(char **argv, int count);
t_array	*initialize_stack_b(t_array *a);
/*	THE ALGORITHM IN SIMPLE TERMS	*/
/*	1. 	Ensure the data is numbers without any repitition.					*/
/*	2. 	Ensure the data set is numbers only in int range					*/
/*	3. 	Put the data in an array.											*/
/*	4. 	Write code for creating the stacks A and B.							*/
/*	5. 	Write code for creating	the moves like push, swap, rotate, etc.		*/
/*	6. 	Find the longest subsequence of numbers.							*/
/*	7. 	Did you consider the list to be circularly sequential.				*/
/*	8. 	Store all the numbers of the subsequence in an array.				*/
/*	9. 	Push numbers not in subsequence in the second stack. 				*/
/*	10. Always keep second stack sorted. 									*/
/*	11. Merge both stacks 													*/
/*	Is point number 12 needed or not? 										*/
/*	12. Rotate to put smallest first. 										*/
/*	make re && ./push_swap 3 4 5 6 1 2	*/

/* TODO: If subsqnc->size == a->size, do nothing */
/* TODO: Check if smallest element is the first element or not */
// TODO: Take care of the problem of exit in case of
// implementation of circular linked list LIS detection.
int	main(int argc, char **argv)
{
	t_array	*a;
	t_array	*subsqnc;
	t_array	*b;

	a = initialize_input(argv, argc - 1);
	b = initialize_stack_b(a);
	subsqnc = fnd_lngst_sbsqnc(a);
	if (subsqnc->size == a->size)
		exit(0);
	push_items_in_b(a, b, subsqnc);
	merge_stacks(a, b);
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
