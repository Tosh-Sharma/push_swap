/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:44:22 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/15 18:44:52 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap(int *array)
{
	ft_swap(&array[0], &array[1]);
}

void	swap_a(int *array)
{
	swap(array);
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(int *array)
{
	swap(array);
	ft_putstr_fd("sb\n", 1);
}

void	swap_ss(int *a, int *b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}

// void	swap_a(int *array)
// {
// 	swap(array);
// 	// ft_putstr_fd("sa\n", 1);
// }

// void	swap_b(int *array)
// {
// 	swap(array);
// 	// ft_putstr_fd("sb\n", 1);
// }

// void	swap_ss(int *a, int *b)
// {
// 	swap(a);
// 	swap(b);
// 	// ft_putstr_fd("ss\n", 1);
// }
