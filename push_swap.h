/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:43:19 by tsharma           #+#    #+#             */
/*   Updated: 2022/08/02 17:18:54 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_array
{
	int	*arr;
	int	size;
}	t_array;

typedef struct array_item
{
	int	number;
	int	index;
}	t_array_item;

/*	HELPERS	*/
void	exit_program(int *numbers);
void	print_array(int *array, int size, char *name);
int		array_contains(t_array *src, int input);

/*	MOVES FOR A	*/
void	rotate_index_and_push_to_a(t_array *a, t_array *b, int index);
void	rotate_to_bottom_and_push(t_array *a, t_array *b, int index);
void	rotate_highest_to_bottom_and_push(t_array *a, t_array *b, int index);

/*	MOVES FOR B	*/
void	bring_index_to_top_and_push(t_array *a, t_array *b, int index);
void	bring_index_to_bottom_and_push(t_array *a, t_array *b, int index);
void	bring_highest_to_bottom_and_push(t_array *a, t_array *b, int index);

/*	CORE ALGO	*/
t_array	*fnd_lngst_sbsqnc(t_array *a);
void	push_items_in_b(t_array *a, t_array *b, t_array *subsqnc);
void	merge_stacks(t_array *a, t_array *b);
void	calculate_min_max(t_array *array,
			t_array_item *min, t_array_item *max);
void	place_in_position(t_array *a, t_array *b,
			t_array_item *min, t_array_item *max);
t_array	*super_lis(t_array *a);

/*	ROTATE	*/
void	rotate_a(t_array *a);
void	rotate_b(t_array *b);
void	rotate_both(t_array *a, t_array *b);
void	rotate_n_times(t_array *array, int n, char name);

/*	PUSH	*/
void	push_to_a(t_array *a, t_array *b);
void	push_to_b(t_array *a, t_array *b);

/*	SWAP	*/
void	swap_a(int *array);
void	swap_b(int *array);
void	swap_ss(int *a, int *b);

/*	REV_ROTATE	*/
void	rev_rotate_a(t_array *a);
void	rev_rotate_b(t_array *b);
void	rev_rotate_both(t_array *a, t_array *b);
void	rev_rotate_n_times(t_array *array, int n, char name);

#endif
