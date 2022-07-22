/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:25:16 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/22 21:59:47 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

#include <stdio.h>

void	print_array(int *array, int size, char *name)
{
	int	i;

	i = 0;
	if (name[0] != '\0' || name != NULL)
		printf("The %s array is: \n", name);
	else
		printf("The array is: \n");
	while (i < size)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
}

void	sort_stacks(t_array *a)
{
	t_array	*subsqnc;
	t_array	*b;

	b = initialize_stack_b(a);
	subsqnc = fnd_lngst_sbsqnc(a);
	print_array(subsqnc->arr, subsqnc->size, "Subsequence");
	// push_items_in_b(a, b, subsqnc);
	// merge_stacks(a, b);
	// rotate_to_smallest_first(a);
}

int	main(int argc, char **argv)
{
	t_array	*a;

	a = initialize_input(argv, argc - 1);
	print_array(a->arr, a->size, "A");
	sort_stacks(a);
	return (0);
}
