/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:08:42 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/08 19:02:07 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three_numbers(t_array *a)
{
	if (a->arr[0] > a->arr[1] && a->arr[0] > a->arr[2])
	{
		rotate_a(a);
		if (a->arr[0] > a->arr[1])
			swap_a(a->arr);
	}
	else if (a->arr[1] > a->arr[0] && a->arr[1] > a->arr[2])
	{
		rev_rotate_a(a);
		if (a->arr[0] > a->arr[1])
			swap_a(a->arr);
	}
	else if (a->arr[0] > a->arr[1])
		swap_a(a->arr);
}
