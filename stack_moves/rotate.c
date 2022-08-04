/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:57:44 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/04 17:32:06 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_array(t_array *array)
{
	int	i;
	int	temp;

	temp = array->arr[0];
	i = 1;
	while (i < array->size)
	{
		array->arr[i - 1] = array->arr[i];
		i++;
	}
	array->arr[array->size - 1] = temp;
}

// void	rotate_a(t_array *a)
// {
// 	rotate_array(a);
// 	ft_putstr_fd("ra\n", 1);
// }

// void	rotate_b(t_array *b)
// {
// 	rotate_array(b);
// 	ft_putstr_fd("rb\n", 1);
// }

// void	rotate_both(t_array *a, t_array *b)
// {
// 	rotate_array(a);
// 	rotate_array(b);
// 	ft_putstr_fd("rr\n", 1);
// }

void	rotate_a(t_array *a)
{
	rotate_array(a);
	// ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_array *b)
{
	rotate_array(b);
	// ft_putstr_fd("rb\n", 1);
}

void	rotate_both(t_array *a, t_array *b)
{
	rotate_array(a);
	rotate_array(b);
	// ft_putstr_fd("rr\n", 1);
}

void	rotate_n_times(t_array *array, int n, char name)
{
	int		i;
	void	(*func)(t_array *);

	i = 0;
	if (name == 'a')
		func = rotate_a;
	else
		func = rotate_b;
	while (i < n)
	{
		func(array);
		i++;
	}
}
