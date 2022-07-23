/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_contains.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:18:59 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/23 18:57:51 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
