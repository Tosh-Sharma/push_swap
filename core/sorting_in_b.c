/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_in_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:57:11 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/15 19:46:47 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_chunk_size(int m_size, int percent)
{
	int	size;

	size = m_size * percent / 100;
	return (size);
}

int	get_size(int percent)
{
	int	size;

	if (100 % percent != 0)
		size = 100 / percent + 1;
	else
		size = 100 / percent;
	return (size);
}

void	free_elements(t_array **elements, t_array *m, t_array *sorted_m,
		int percent)
{
	int	i;

	i = 0;
	while (i < get_size(percent))
	{
		free_array(elements[i]);
		i++;
	}
	free(elements);
	free_array(m);
	free_array(sorted_m);
}

t_array	**get_chunks_to_insert(t_array *sorted_m, int percent)
{
	t_array	**elements;
	t_array	*chunk;
	int		i;
	int		start;
	int		end;

	elements = (t_array **)malloc(sizeof(t_array *) * get_size(percent));
	start = sorted_m->size - 1;
	end = sorted_m->size - get_chunk_size(sorted_m->size, percent);
	i = 0;
	while (i < get_size(percent))
	{
		chunk = slice_array(sorted_m, end, start);
		elements[i] = chunk;
		start = end - 1;
		end = start - get_chunk_size(sorted_m->size, percent);
		if (end < 0)
			end = 0;
		i++;
	}
	return (elements);
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

	percent = calculate_percent(a, b);
	m = calculate_m(a, subsqnc);
	sorted_m = copy_and_sort(m);
	elements = get_chunks_to_insert(sorted_m, percent);
	counter = 0;
	while (a->size != subsqnc->size)
	{
		move_items_to_b(a, b, elements[counter]);
		counter++;
	}
	free_array(subsqnc);
	free_elements(elements, m, sorted_m, percent);
}
