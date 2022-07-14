/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:25:16 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/14 17:39:56 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void	sort_numbers(int *numbers)
{
}

int	perform_atoi(char **argv, int *numbers)
{
	return (0);
}

//	Things to do in the code.
//	1. Check if input is all numbers, if not, return Error
//	2. Once you have numbers, insert them into the stack & start operations
//	3. You need to write the code for sorting out the stuff
// 	every time you do the operations, output the steps on console
int	push_swap(int argc, char **argv)
{
	int	*numbers;

	if (perform_atoi(argv, numbers) == 0)
		ft_printf("Error\n");
	else
		sort_numbers(numbers);
	return (0);
}
