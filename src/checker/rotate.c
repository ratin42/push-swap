/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 21:32:34 by ratin             #+#    #+#             */
/*   Updated: 2019/06/05 00:43:08 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_rotate(t_pile **pile)
{
	t_pile	*tmp;
	t_pile	*last;

	tmp = *pile;
	*pile = (*pile)->next;
	last = *pile;
	tmp->next = NULL;
	while (last->next)
		last = last->next;
	last->next = tmp;
}

void		rotate(t_push *push, char pile)
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
	do_rotate(src);
}

void		rotate_rotate(t_push *push)
{
	rotate(push, 'a');
	rotate(push, 'b');
}
