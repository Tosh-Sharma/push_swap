/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:57:44 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/23 18:02:05 by tsharma          ###   ########.fr       */
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

void	rotate_a(t_array *a)
{
	rotate_array(a);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_array *b)
{
	rotate_array(b);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_both(t_array *a, t_array *b)
{
	rotate_array(a);
	rotate_array(b);
	ft_putstr_fd("rr\n", 1);
}

// int	main(void)
// {
// 	int	*array;
// 	int	i;

// 	array = (int *)malloc(sizeof(int) * 5);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		array[i] = i;
// 		i++;
// 	}
// 	print_array(array, 5);
// 	rotate_a(array, 5);
// 	print_array(array, 5);
// 	rotate_a(array, 5);
// 	print_array(array, 5);
// 	rotate_b(array, 5);
// 	print_array(array, 5);
// 	rotate_both(array, 5, array, 5);
// 	print_array(array, 5);
// 	return (0);
// }
