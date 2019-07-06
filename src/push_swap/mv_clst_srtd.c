/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_clst_srtd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 01:52:58 by ratin             #+#    #+#             */
/*   Updated: 2019/07/06 02:15:38 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile		*get_target(t_push *push, int way)
{
	t_pile	*last;

	last = push->pile_a;
	if (way == 1)
	{
		while (last->next)
		{
			if (last->sorted == 1)
				return (last);
			last = last->next;
		}
	}
	else
	{
		while (last->next)
			last = last->next;
		while (last->prev)
		{
			if (last->sorted == 1)
				return (last);
			last = last->prev;
		}
	}
	return (last);
}

static int	get_back(t_pile *last)
{
	int		back;

	back = 0;
	while (last->prev)
	{
		if (last->sorted == 1)
			break ;
		last = last->prev;
		back++;
	}
	return (back);
}

static int	get_front(t_pile *last)
{
	int		front;

	front = 0;
	while (last->next)
	{
		if (last->sorted == 1)
			break ;
		last = last->next;
		front++;
	}
	return (front);
}

t_pile		*found_target(t_push *push)
{
	t_pile	*last;
	int		front;
	int		back;

	last = push->pile_a;
	front = get_front(last);
	while (last->next)
		last = last->next;
	back = get_back(last);
	if (front < back)
		return (get_target(push, 1));
	else
		return (get_target(push, 2));
}

void		move_closest_sorted(t_push *push)
{
	t_pile	*first;

	first = found_target(push);
	move_first_top(push, first);
}
