/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <Raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 04:51:14 by ratin             #+#    #+#             */
/*   Updated: 2019/07/03 14:12:24 by Raphael          ###   ########.fr       */
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

void		print_pile_reverse(t_push *push)
{
	t_pile *last;
	
	print_pile(push);
	last = push->pile_a;
	while (last->next)
		last = last->next;
	while (last)
	{
		printf("%d\n", last->nbr);
		last = last->prev;
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
			if (last->sorted == 1 && len_pile(push, 'a') > 3)
			{
				move_first_top(push, last);
				make_move(push, "pb");
				if (push->pile_b && push->pile_b->next
				&& push->pile_b->next > push->pile_b)
					make_move(push, "sb");
			}
			if (last->nbr < step)
				last->sorted = 1;
			last = last->next;
		}
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
/* 	while (len_pile(push, 'a') > 3)
		make_move(push, "pb"); */

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

void		do_sort(t_push *push)
{
	//for (int i = 0; i < 2; i++)
	while (check_sort(push) == 0)
	{
		working_stack_a(push);
		working_stack_b(push);
	}
}