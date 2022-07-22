/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:57:44 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/22 18:58:25 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_array(int *array, int size)
{
	int	i;
	int	temp;

	temp = array[0];
	i = 1;
	while (i < size)
	{
		array[i - 1] = array[i];
		i++;
	}
	array[size - 1] = temp;
}

void	rotate_a(int *a, int size)
{
	rotate_array(a, size);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(int *b, int size)
{
	rotate_array(b, size);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_both(int *a, int size_a, int *b, int size_b)
{
	rotate_array(a, size_a);
	rotate_array(b, size_b);
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
