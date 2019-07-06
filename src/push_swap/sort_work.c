/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 04:51:14 by ratin             #+#    #+#             */
/*   Updated: 2019/07/06 01:56:02 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_drain(t_push *push)
{
	t_pile	*last;

	last = push->pile_a;
	while (last && len_pile(push, 'a') > 3)
	{
		if (last->sorted == 1)
			return (0);
		last = last->next;
	}
	return (1);
}

void		drain_sorted(t_push *push)
{
	while (check_drain(push) == 0)
	{
		if (len_pile(push, 'a') > 3)
		{
			move_closest_sorted(push);
			make_move(push, "pb");
		}
	}
}

void		inteligent_drain(t_push *push)
{
	t_pile	*last;
	int		step;
	int		add;

	step = 50;
	add = 50;
	if (len_pile(push, 'a') < 150)
	{
		step = 10;
		add = 10;
	}
	while (len_pile(push, 'a') > 3)
	{
		last = push->pile_a;
		while (last)
		{
			if (last->nbr < step)
				last->sorted = 1;
			last = last->next;
		}
		drain_sorted(push);
		step += add;
	}
}
