/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:57:47 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/20 17:41:04 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_array
{
	int	*arr;
	int	size;
}	t_array;

/* First you move array two's item by plus one index */
/* Then you add top item of array one into array two */
/* After this, you move all of the items from array  */
/* one from index = 1 to index = 0					 */
/* Update size variable of array two and array one	 */
void	push_from_one_to_two(t_array *one, t_array *two)
{
}

/* Push from the top of A to B. */
void	push_to_b(t_array *a, t_array *b)
{
	push_from_one_to_two(a, b);
	printf("pb\n");
	// ft_putstr_fd("pa", 1);
}

/* Push from the top of B to A. */
void	push_to_a(t_array *a, t_array *b)
{
	push_from_one_to_two(b, a);
	printf("pa\n");
	// ft_putstr_fd("pa", 1);
}

int	main(void)
{
	int		*a;
	int		*b;
	t_array	*t_a;
	t_array	*t_b;
	int		i;

	a = (int *)malloc(sizeof(int) * 10);
	b = (int *)malloc(sizeof(int) * 10);
	i = 0;
	while (i < 10)
	{
		a[i] = 50 + i;
		i++;
	}
	t_a->arr = a;
	t_a->size = 10;
	t_b->arr = b;
	t_b->size = 10;
	printf("Original array A is \n");
	i = 0;
	while (i < t_a->size)
	{
		printf("%d ", t_a->arr[i]);
		i++;
	}
	printf("\n");
	push_from_a_to_b(t_a, t_b);
	push_from_a_to_b(t_a, t_b);
	push_from_a_to_b(t_a, t_b);
	push_from_a_to_b(t_a, t_b);
	printf("Updated array A is \n");
	i = 0;
	while (i < t_a->size)
	{
		printf("%d ", t_a->arr[i]);
		i++;
	}
}
