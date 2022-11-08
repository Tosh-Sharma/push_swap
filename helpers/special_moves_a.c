/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_moves_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:17:03 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/08 13:35:00 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_index_and_push_to_a(t_array *a, t_array *b,
		int index, int push)
{
	if ((index + 1) <= (a->size / 2))
		rotate_n_times(a, index, 'a');
	else
		rev_rotate_n_times(a, a->size - index, 'a');
	if (push == 1)
		push_to_a(a, b);
}

void	rotate_to_top_and_push(t_array *a,
	t_array *b, int index)
{
	if ((index + 1) <= (a->size / 2))
		rotate_n_times(a, index, 'a');
	else
		rev_rotate_n_times(a, a->size - index, 'a');
	push_to_a(a, b);
}

void	rotate_highest_to_bottom_and_push(t_array *a,
	t_array *b, int index)
{
	if ((index + 1) <= (a->size / 2))
		rotate_n_times(a, index + 1, 'a');
	else
		rev_rotate_n_times(a, a->size - 1 - index, 'a');
	push_to_a(a, b);
}
