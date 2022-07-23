/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:31:38 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/23 18:22:51 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// TODO: Need to delete this file because the printf used
// is from stdio.h and hence is not needed.
void	print_array(int *array, int size, char *name)
{
	int	i;

	i = 0;
	if (name[0] != '\0' || name != NULL)
		printf("The %s array is: \n", name);
	else
		printf("The array is: \n");
	while (i < size)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
}
