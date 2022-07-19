/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:04:46 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/19 16:49:54 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	exit_program(int *a)
{
	free(a);
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

int	*initialize_stack_b(int count, int *a)
{
	int	*array;

	array = (int *)malloc(sizeof(int) * count);
	if (!array)
	{
		free(a);
		exit(0);
	}
	return (array);
}
