/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_sort_replace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <Raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:36:34 by Raphael           #+#    #+#             */
/*   Updated: 2019/07/04 06:08:10 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile		*get_next_element(t_push *push, t_pile *element)
{
	if (element->next == NULL)
		return (push->pile_a);
	return (element->next);
}

int			found_closest(t_push *push, t_pile	*first)
{
	t_pile	*last;
	int		front;
	int		back;

	front = 0;
	back = 0;
	last = push->pile_a;
	while (last->next)
		last = last->next;
	while (last->prev)
	{
		if (last->nbr == first->nbr)
			break ;
		last = last->prev;
		back++;
	}
	last = push->pile_a;
	while (last->next)
	{
		if (last->nbr == first->nbr)
			break ;
		last = last->next;
		front++;
	}
	if (front < back)
		return (1);
	else
		return (2);
}

void		move_first_top(t_push *push, t_pile *first)
{
	int		way;

	way = found_closest(push, first);
	while (push->pile_a->nbr != first->nbr)
	{
		if (way == 1)
			make_move(push, "ra");
		else
			make_move(push, "rra");
	}
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
