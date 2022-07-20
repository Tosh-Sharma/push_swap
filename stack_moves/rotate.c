/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:57:44 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/20 21:12:58 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_array(int *array)
{
}

void	rotate_a(int *a)
{
	rotate_array(a);
	ft_putstr_fd("ra", 1);
}

void	rotate_b(int *b)
{
	rotate_array(b);
	ft_putstr_fd("rb", 1);
}

void	rotate_both(int *a, int *b)
{
	rotate_array(a);
	rotate_array(b);
	ft_putstr_fd("rr", 1);
}
