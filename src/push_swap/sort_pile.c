/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 04:40:25 by ratin             #+#    #+#             */
/*   Updated: 2019/07/06 01:55:21 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_sort(t_push *push)
{
	t_pile	*last;

	last = push->pile_a;
	while (last->next)
	{
		if (last->nbr > last->next->nbr)
			return (0);
		last = last->next;
	}
	if (push->pile_b != NULL)
		return (0);
	return (1);
}

void		do_little_sort(t_push *push)
{
	int		top;
	int		middle;
	int		bottom;

	top = push->pile_a->nbr;
	middle = push->pile_a->next->nbr;
	bottom = push->pile_a->next->next->nbr;
	if (top > middle && middle < bottom && bottom > top)
		make_move(push, "sa");
	else if (top > middle && middle > bottom && bottom < top)
	{
		make_move(push, "sa");
		make_move(push, "rra");
	}
	else if (top > middle && middle < bottom && bottom < top)
		make_move(push, "ra");
	else if (top < middle && middle > bottom && bottom > top)
	{
		make_move(push, "sa");
		make_move(push, "ra");
	}
	else if (top < middle && middle > bottom && bottom < top)
		make_move(push, "rra");
}

void		do_mid_sort(t_push *push)
{
	t_pile	*first;
	t_pile	*last;

	if (check_sort(push) == 1)
		return ;
	inteligent_drain(push);
	do_little_sort(push);
	while (len_pile(push, 'b') != 0)
		mid_sort_replace(push);
	last = push->pile_a;
	first = push->pile_a;
	while (last)
	{
		if (first->nbr > last->nbr)
			first = last;
		last = last->next;
	}
	move_first_top(push, first);
}

void		sort_pile(t_push *push)
{
	if (len_pile(push, 'a') == 3)
		do_little_sort(push);
	else if (len_pile(push, 'a') == 2
	&& push->pile_a->nbr > push->pile_a->next->nbr)
		make_move(push, "sa");
	else
		do_mid_sort(push);
}
