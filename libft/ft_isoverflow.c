/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isoverflow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:38:52 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/17 19:52:00 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	is_overflow(char *str, int is_neg)
{
	printf("str is %s\n", str);
	if (ft_strlen(str) > 10)
		return (1);
	if (ft_strlen == 10)
	{
		if (str[0] > 50)
			return (1);
		else if (str[0] == 50)
		{
		}
	}
	return (0);
}
