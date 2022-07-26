/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:16:48 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/26 14:23:17 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bring_index_to_top_and_push(t_array *a, t_array *b,
	int index)
{
	if ((index + 1) <= (b->size) / 2)
		rotate_n_times(b, index, 'b');
	else
		rev_rotate_n_times(b, b->size - index, 'b');
	push_to_b(a, b);
}

void	bring_index_to_bottom_and_push(t_array *a, t_array *b, int index)
{
	if ((index + 1) <= (b->size / 2))
		rev_rotate_n_times(b, index + 1, 'b');
	else
		rotate_n_times(b, b->size - 1 - index, 'b');
	push_to_b(a, b);
}

void	rotate_index_and_push_to_a(t_array *a, t_array *b, int index)
{
	if ((index + 1) <= (a->size / 2))
		rotate_n_times(a, index, 'a');
	else
		rev_rotate_n_times(a, a->size - index, 'a');
	push_to_a(a, b);
}

void	rotate_to_bottom_and_push(t_array *a,
	t_array *b, int index)
{
	if ((index + 1) <= (a->size / 2))
		rev_rotate_n_times(a, index + 1, 'a');
	else
		rotate_n_times(a, a->size - 1 - index, 'a');
	push_to_a(a, b);
}
