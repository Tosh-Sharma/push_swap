/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:15:47 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/14 21:20:12 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_array(t_array *input)
{
	int	i;
	int	temp;

	i = 0;
	while (i < input->size / 2)
	{
		temp = input->arr[i];
		input->arr[i] = input->arr[input->size - 1 - i];
		input->arr[input->size - 1 - i] = temp;
		i++;
	}
}
