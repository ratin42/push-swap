/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_first_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 02:07:23 by ratin             #+#    #+#             */
/*   Updated: 2019/07/06 02:14:39 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_back(t_pile *last, t_pile *first)
{
	int		back;

	back = 0;
	while (last->prev)
	{
		if (last->nbr == first->nbr)
			break ;
		last = last->prev;
		back++;
	}
	return (back);
}

static int	get_front(t_pile *last, t_pile *first)
{
	int		front;

	front = 0;
	while (last->next)
	{
		if (last->nbr == first->nbr)
			break ;
		last = last->next;
		front++;
	}
	return (front);
}

int			found_closest(t_push *push, t_pile *first)
{
	t_pile	*last;
	int		front;
	int		back;

	last = push->pile_a;
	front = get_front(last, first);
	while (last->next)
		last = last->next;
	back = get_back(last, first);
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
