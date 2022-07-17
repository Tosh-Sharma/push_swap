/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:25:16 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/17 18:48:57 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

/*	1. Put the data in an array.									*/
/*	2. Find the longest subsequence of numbers.						*/
/*	(Consider the list to be circularly sequential while doing so) 	*/
/*	3. Store all the numbers of the subsequence in an array.		*/
/*	4. Push numbers not in subsequence in the second stack. 		*/
/*	5. Always keep second stack sorted. 							*/
/*	6. Merge both stacks 											*/
/*	7. Rotate to put smallest first. 								*/
void	sort_the_numbers(int *numbers, int count)
{
	int		i;
	t_array	*subsqnc;

	i = 0;
	printf("\nThe numbers are as below\n");
	while (i < count)
	{
		printf("numbers[%d]: %d\n", i, numbers[i]);
		i++;
	}
	subsqnc = fnd_lngst_sbsqnc(numbers, count);
}

int	*parse_input(char **argv, int count)
{
	int	i;
	int	j;
	int	*numbers;

	i = 1;
	numbers = (int *)malloc(sizeof(int) * count);
	while (i <= count)
	{
		numbers[i - 1] = ft_atoi(argv[i], numbers);
		j = 0;
		while (j < i - 1)
		{
			if (numbers[j] == numbers[i - 1])
				exit_program(numbers);
			j++;
		}
		i++;
	}
	return (numbers);
}

int	main(int argc, char **argv)
{
	int	*numbers;

	numbers = parse_input(argv, argc - 1);
	sort_the_numbers(numbers, argc - 1);
	return (0);
}
