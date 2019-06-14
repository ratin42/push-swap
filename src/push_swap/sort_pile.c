/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 04:40:25 by ratin             #+#    #+#             */
/*   Updated: 2019/06/08 06:23:38 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_last(t_push *push, char pile)
{
	t_pile	*last;

	if (pile == 'a')
		last = push->pile_a;
	else
		last = push->pile_b;
	while (last->next)
		last = last->next;
	return (last->nbr);
}

int			put_pivot(t_push *push, char pile)
{
	int		nbr;
	t_pile	*last;

	last = push->pile_a;
	while (last != NULL && last->sorted == 1)
		last = last->next;
	last->pivot = 1;
	nbr = last->nbr;
	while (get_last(push, 'a') != nbr)
		make_move(push, "ra");
	(void)pile;
	return (nbr);
}

/* int			put_pivot(t_push *push, char pile)
{
	t_pile	*last;
	int		median;
	
	median = 1;
	if (pile == 'a')
		last = push->pile_a;
	else
		last = push->pile_b;
	while (last)
	{
		if (median == len_pile(push, pile) / 2)
		{
			last->pivot = 1;
			return (last->nbr);
		}
		median++;
		last = last->next;
	}
	return (ERROR);
} */

void		sort_pile(t_push *push)
{
	do_sort(push);
}