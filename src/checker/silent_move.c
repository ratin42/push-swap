/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 02:18:50 by ratin             #+#    #+#             */
/*   Updated: 2019/07/06 02:23:10 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		silent_make_move_3(t_push *push, char *str)
{
	if (ft_strcmp(str, "rra") == 0)
		reverse_rotate(push, 'a');
	if (ft_strcmp(str, "rrb") == 0)
		reverse_rotate(push, 'b');
	if (ft_strcmp(str, "rrr") == 0)
		reverse_reverse(push);
}

void		silent_make_move_2(t_push *push, char *str)
{
	if (ft_strcmp(str, "pb") == 0)
		push_move(push, 'b');
	if (ft_strcmp(str, "ra") == 0)
		rotate(push, 'a');
	if (ft_strcmp(str, "rb") == 0)
		rotate(push, 'b');
	if (ft_strcmp(str, "rr") == 0)
		rotate_rotate(push);
	silent_make_move_3(push, str);
}

void		silent_make_move(t_push *push, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		swap(push, 'a');
	if (ft_strcmp(str, "sb") == 0)
		swap(push, 'b');
	if (ft_strcmp(str, "ss") == 0)
		swap_swap(push);
	if (ft_strcmp(str, "pa") == 0)
		push_move(push, 'a');
	silent_make_move_2(push, str);
	replace_prev(push);
}
