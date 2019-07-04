/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <Raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 04:51:14 by ratin             #+#    #+#             */
/*   Updated: 2019/07/04 06:03:48 by Raphael          ###   ########.fr       */
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

t_pile		*found_target(t_push *push)
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
		if (last->sorted == 1)
			break ;
		last = last->prev;
		back++;
	}
	last = push->pile_a;
	while (last->next)
	{
		if (last->sorted == 1)
			break ;
		last = last->next;
		front++;
	}
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

	if (len_pile(push, 'a') < 150)
	{
		step = 10;
		add = 10;
	}
	else
	{
		step = 50;
		add = 50;
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
