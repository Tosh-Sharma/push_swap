/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:04:46 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/25 18:32:41 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// TODO: Error goes on Standard Error (FD = 2 and not 1)
void	exit_program(int *a)
{
	free(a);
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

/*	If src array contains input element, return 1. */
/*	Else return 0. */
int	array_contains(t_array *src, int input)
{
	int	i;

	i = 0;
	while (i < src->size)
	{
		if (src->arr[i] == input)
			return (1);
		i++;
	}
	if (i == src->size)
		return (0);
	return (0);
}

void	bring_index_to_top_and_push(t_array *a, t_array *b,
	int index)
{
	if ((index + 1) <= (b->size) / 2)
		rotate_n_times(b, index, 'b');
	else
		rev_rotate_n_times(b, b->size - index, 'b');
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
