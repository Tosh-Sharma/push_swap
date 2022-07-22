/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:31:27 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/22 21:52:31 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

t_array	*initialize_input(char **argv, int count)
{
	int		i;
	int		j;
	int		*numbers;
	t_array	*a;

	i = 1;
	a = (t_array *)malloc(sizeof(t_array));
	numbers = (int *)malloc(sizeof(int) * count);
	while (i <= count)
	{
		numbers[i - 1] = ft_superatoi(argv[i], numbers);
		j = 0;
		while (j < i - 1)
		{
			if (numbers[j] == numbers[i - 1])
				exit_program(numbers);
			j++;
		}
		i++;
	}
	a->arr = numbers;
	a->size = count;
	return (a);
}
