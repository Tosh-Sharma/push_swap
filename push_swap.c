/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:25:16 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/15 19:02:01 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void	sort_numbers(int *numbers, int count)
{
	int	i;

	i = 0;
	printf("\nThe numbers are as below\n");
	while (i < count)
	{
		printf("numbers[%d]: %d\n", i, numbers[i]);
		i++;
	}
}

int	*perform_atoi(char **argv, int count)
{
	int	i;
	int	*numbers;

	i = 1;
	numbers = (int *)malloc(sizeof(int) * count);
	while (i <= count)
	{
		numbers[i - 1] = ft_atoi(argv[i], numbers);
		i++;
	}
	return (numbers);
}

//	Things to do in the code.
//	1. Check if input is all numbers, if not, return Error
//	2. Once you have numbers, insert them into the stack & start operations
//	3. You need to write the code for sorting out the stuff
// 	every time you do the operations, output the steps on console
int	main(int argc, char **argv)
{
	int	*numbers;

	numbers = perform_atoi(argv, argc - 1);
	sort_numbers(numbers, argc - 1);
	return (0);
}
