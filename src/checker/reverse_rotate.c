/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 23:08:59 by ratin             #+#    #+#             */
/*   Updated: 2019/06/05 00:41:47 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_rrotate(t_pile **pile)
{
	t_pile	*tmp;
	t_pile	*last;

	last = *pile;
	while (last->next->next)
		last = last->next;
	tmp = last;
	last = last->next;
	last->next = *pile;
	*pile = last;
	tmp->next = NULL;
}

void		reverse_rotate(t_push *push, char pile)
{
	t_pile	**src;

	if (pile == 'a')
	{
		if (push->pile_a == NULL || push->pile_a->next == NULL)
			return ;
		src = &push->pile_a;
	}
	else
	{
		if (push->pile_b == NULL || push->pile_b->next == NULL)
			return ;
		src = &push->pile_b;
	}
	do_rrotate(src);
}

void		reverse_reverse(t_push *push)
{
	reverse_rotate(push, 'a');
	reverse_rotate(push, 'b');
}
