/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   working_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 02:35:46 by ratin             #+#    #+#             */
/*   Updated: 2019/06/09 10:21:28 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			start_up_sort(t_push *push, char pile, int pivot)
{
	t_pile	*last;
	t_pile	*tmp;

	if (pile == 'a')
		last = push->pile_a;
	else
		last = push->pile_b;
	while (last)
	{
		if (last->sorted == 1)
		{
			tmp = last->next;
			make_move(push, "ra");
			last = tmp;
			continue ;
		}
		if (last->pivot == 1)
			break ;
		if (last->nbr < pivot)
		{
			tmp = last->next;
			make_move(push, "pb");
			last = tmp;
			continue ;
		}
		else
		{
			tmp = last->next;
			make_move(push, "ra");
			last = tmp;
			continue ;
		}
		last = last->next;
	}
	if (push->pile_a->sorted == 0)
		make_move(push, "pb");
	if (len_pile_sorted(push, 'a') <= 1)
		return (1);
	else
		return (0);
}

void	working_stack_a(t_push *push)
{
	int		pivot;
	int		stop;

	stop = 0;
	while (stop == 0)
	{
		pivot = put_pivot(push, 'a');
		stop = start_up_sort(push, 'a', pivot);
	}
	if (len_pile(push, 'a') == 1)
		push->pile_a->sorted = 1;
}