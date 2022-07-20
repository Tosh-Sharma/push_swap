/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:57:41 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/20 21:09:04 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rotate_a(int *a)
{
	rev_rotate_array(a);
	ft_putstr_fd("rra", 1);
}

void	rev_rotate_b(int *b)
{
	rev_rotate_array(b);
	ft_putstr_fd("rrb", 1);
}

void	rev_rotate_array(int *array)
{
}

void	rev_rotate_both(int *a, int *b)
{
	rev_rotate_array(a);
	rev_rotate_array(b);
	ft_putstr_fd("rrr", 1);
}
