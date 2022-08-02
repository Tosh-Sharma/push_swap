/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:16:48 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/02 17:16:38 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bring_index_to_top_and_push(t_array *a, t_array *b,
	int index)
{
	if ((index + 1) <= (b->size / 2))
		rotate_n_times(b, index, 'b');
	else
		rev_rotate_n_times(b, b->size - index, 'b');
	push_to_b(a, b);
}

void	bring_index_to_bottom_and_push(t_array *a, t_array *b, int index)
{
	if (index != 0)
	{
		if ((index + 1) <= (b->size / 2))
			rotate_n_times(b, index, 'b');
		else
			rev_rotate_n_times(b, b->size - index, 'b');
	}
	push_to_b(a, b);
}

void	bring_highest_to_bottom_and_push(t_array *a,
	t_array *b, int index)
{
	if ((index + 1) <= (b->size / 2))
		rotate_n_times(b, index + 1, 'b');
	else
		rev_rotate_n_times(b, b->size - 1 - index, 'b');
	push_to_b(a, b);
}
