/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:43:19 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/22 21:53:10 by tsharma          ###   ########.fr       */
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

void	exit_program(int *numbers);
t_array	*fnd_lngst_sbsqnc(t_array *a);
t_array	*initialize_input(char **argv, int count);
t_array	*initialize_stack_b(t_array *a);
void	push_items_in_b(t_array *a, t_array *b, t_array *subsqnc);
void	merge_stacks(t_array *a, t_array *b);
void	rotate_to_smallest_first(t_array *a);

#endif
