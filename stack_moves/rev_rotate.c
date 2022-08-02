/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:57:41 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/02 18:18:46 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Shift down all elements of stack by one */
/* The last element becomes the first one. */
void	rev_rotate_array(t_array *array)
{
	int	i;
	int	temp;

	temp = array->arr[array->size - 1];
	i = array->size - 1;
	while (i > 0)
	{
		array->arr[i] = array->arr[i - 1];
		i--;
	}
	array->arr[0] = temp;
}

void	rev_rotate_a(t_array *a)
{
	rev_rotate_array(a);
	ft_putstr_fd("rra\n", 1);
}

void	rev_rotate_b(t_array *b)
{
	rev_rotate_array(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rev_rotate_both(t_array *a, t_array *b)
{
	rev_rotate_array(a);
	rev_rotate_array(b);
	ft_putstr_fd("rrr\n", 1);
}

void	rev_rotate_n_times(t_array *array, int n, char name)
{
	int		i;
	void	(*func)(t_array *);

	i = 0;
	if (name == 'a')
		func = rev_rotate_a;
	else
		func = rev_rotate_b;
	while (i < n)
	{
		func(array);
		i++;
	}
}
