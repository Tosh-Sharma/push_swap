/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_in_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:57:11 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/17 22:11:37 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_elements(t_array **elements, t_array *m, t_array *sorted_m)
{
	free(m->arr);
	free(m);
	free(sorted_m->arr);
	free(sorted_m);
}

t_array	**get_chunks_to_insert(t_array *sorted_m, int percent)
{
}

//	Algorithm to sort data into B in the most efficient manner
//	1. m = n - l1
//	2. sorted_m = array obtained after sorting "m"
//	3. Now, calculate percentage of elements to move 'p'.
//	4. Start adding 'p%' numbers at the bottom and move upwards.
//	5. Return code when only lis remains in a.
void	sort_into_b(t_array *a, t_array *b, t_array *subsqnc)
{
	t_array		*m;
	t_array		*sorted_m;
	t_array		**elements;
	int			percent;
	int			counter;

	percent = calculate_percent(a, b, subsqnc);
	m = calculate_m(a, subsqnc);
	sorted_m = copy_and_sort(m);
	elements = get_chunks_to_insert(sorted_m, percent);
	counter = 0;
	while (a->size != subsqnc->size)
	{
		move_items_to_b(a, b, elements[counter], subsqnc);
		counter++;
	}
	free_elements(elements, m, sorted_m);
}
