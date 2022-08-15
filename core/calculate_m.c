/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_m.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:03:05 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/15 18:08:23 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_array	*calculate_m(t_array *a, t_array *subsqnc)
{
	t_array	*m;
	int		i;
	int		j;

	m = (t_array *)malloc(sizeof(t_array));
	m->size = a->size - subsqnc->size;
	m->arr = (int *)malloc(sizeof(int) * m->size);
	i = 0;
	j = 0;
	while (i < a->size)
	{
		if (!arr_cntns(subsqnc, a->arr[i]))
		{
			m->arr[j] = a->arr[i];
			j++;
		}
		i++;
	}
	return (m);
}

int	calculate_percent(t_array *a, t_array *b, t_array *subsqnc, int counter)
{
	int	percent;

	percent = 20 + (4 * counter);
	if (b->size > a->size || subsqnc->size > a->size / 4)
		percent = 30;
	percent = 20;
	return (percent);
}
