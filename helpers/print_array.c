/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:31:38 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/22 18:09:39 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_array(int *array, int size)
{
	int	i;

	i = 0;
	printf("The array is: \n");
	while (i < size)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
}
