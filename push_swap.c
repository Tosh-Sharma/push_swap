/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:25:16 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/23 19:34:33 by tsharma          ###   ########.fr       */
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
/*	make re && ./push_swap 3 4 5 6 1 2	*/

/* TODO: If subsqnc->size == a->size, do nothing */
/* TODO: Check if smallest element is the first element or not */
void	sort_stacks(t_array *a)
{
	t_array	*subsqnc;
	t_array	*b;

	b = initialize_stack_b(a);
	subsqnc = fnd_lngst_sbsqnc(a);
	if (subsqnc->size == a->size)
		exit(0);
	push_items_in_b(a, b, subsqnc);
	// merge_stacks(a, b);
	// rotate_to_smallest_first(a);
}

int	main(int argc, char **argv)
{
	t_array	*a;

	a = initialize_input(argv, argc - 1);
	sort_stacks(a);
	return (0);
}
