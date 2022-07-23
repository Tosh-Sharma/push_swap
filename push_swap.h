/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:43:19 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/23 18:40:38 by tsharma          ###   ########.fr       */
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

/*	HELPERS	*/
void	exit_program(int *numbers);
void	print_array(int *array, int size, char *name);
int		array_contains(t_array *src, int input);

/*	INITIALIZERS	*/
t_array	*initialize_input(char **argv, int count);
t_array	*initialize_stack_b(t_array *a);

/*	CORE ALGO	*/
t_array	*fnd_lngst_sbsqnc(t_array *a);
void	push_items_in_b(t_array *a, t_array *b, t_array *subsqnc);
void	merge_stacks(t_array *a, t_array *b);
void	rotate_to_smallest_first(t_array *a);

/*	ROTATE	*/
void	rotate_a(t_array *a);
void	rotate_b(t_array *b);
void	rotate_both(t_array *a, t_array *b);

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

#endif
