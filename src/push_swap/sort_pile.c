/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <Raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 04:40:25 by ratin             #+#    #+#             */
/*   Updated: 2019/07/03 13:45:26 by Raphael          ###   ########.fr       */
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

void		sort_pile(t_push *push)
{
	if (len_pile(push, 'a') == 3)
		do_little_sort(push);
	else if (len_pile(push, 'a') == 2
	&& push->pile_a->nbr > push->pile_a->next->nbr)
		make_move(push, "sa");
	else if (len_pile(push, 'a') <= 1000)
		do_mid_sort(push);
	else
		do_sort(push);
	//print_pile(push);
}