/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:57:47 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/20 21:04:14 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 1. First you move array two's item by plus one index */
/* 2. Then you add top item of array one into array two */
/* 3. After this, you move all of the items from array  */
/* one from index = 1 to index = 0					 	*/
/* 4. Update size variable of array two and array one	*/
void	push_from_one_to_two(t_array *one, t_array *two)
{
	int	i;

	i = two->size - 1;
	while (i >= 0)
	{
		two->arr[i + 1] = two->arr[i];
		i--;
	}
	two->arr[0] = one->arr[0];
	two->size = two->size + 1;
	i = 0;
	while (i < one->size - 1)
	{
		one->arr[i] = one->arr[i + 1];
		i++;
	}
	one->size = one->size - 1;
}

/* Push from the top of A to B. */
void	push_to_b(t_array *a, t_array *b)
{
	push_from_one_to_two(a, b);
	ft_putstr_fd("pb\n", 1);
}

/* Push from the top of B to A. */
void	push_to_a(t_array *a, t_array *b)
{
	push_from_one_to_two(b, a);
	ft_putstr_fd("pa\n", 1);
}
