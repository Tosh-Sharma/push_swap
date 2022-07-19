/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:25:16 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/19 16:55:49 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

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

void	sort_stacks(int *a, int count)
{
	t_array	*subsqnc;
	int		*b;

	b = initialize_stack_b(count, a);
	subsqnc = fnd_lngst_sbsqnc(a, count);
	push_items_in_b(a, b, subsqnc, count);
	merge_stacks(a, b);
	rotate_to_smallest_first(a);
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*lngst_sbsqnc;

	a = initialize_input(argv, argc - 1);
	sort_stacks(a, argc - 1);
	return (0);
}
