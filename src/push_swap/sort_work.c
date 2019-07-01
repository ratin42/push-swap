/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <Raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 04:51:14 by ratin             #+#    #+#             */
/*   Updated: 2019/06/28 17:19:41 by Raphael          ###   ########.fr       */
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
	while (len_pile(push, 'a') > 3)
		make_move(push, "pb");
	do_little_sort(push);
	while (len_pile(push, 'b') != 0)
	{
		//make_move(push, "pa");
		mid_sort_replace(push);
	}
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