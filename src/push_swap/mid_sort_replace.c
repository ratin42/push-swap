/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_sort_replace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:36:34 by Raphael           #+#    #+#             */
/*   Updated: 2019/07/06 02:07:54 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile		*get_next_element(t_push *push, t_pile *element)
{
	if (element->next == NULL)
		return (push->pile_a);
	return (element->next);
}

void		rotate_placement(t_push *push)
{
	t_pile	*last;
	t_pile	*first;
	int		first_save;
	int		to_place;

	to_place = push->pile_b->nbr;
	last = push->pile_a;
	first = last;
	while (last)
	{
		if (last->nbr < first->nbr)
			first = last;
		last = last->next;
	}
	first_save = first->nbr;
	while (first->nbr < to_place)
	{
		first = get_next_element(push, first);
		if (first->nbr == first_save)
			break ;
	}
	move_first_top(push, first);
}

void		mid_sort_replace(t_push *push)
{
	t_pile	*element;

	element = push->pile_a;
	rotate_placement(push);
	make_move(push, "pa");
}
