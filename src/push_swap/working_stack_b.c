/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   working_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 03:01:01 by ratin             #+#    #+#             */
/*   Updated: 2019/06/08 06:55:48 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void		sort_b(t_push *push)
{
	x
}
 */
void		working_stack_b(t_push *push)
{
	t_pile	*last;
	t_pile	*tmp;

	last = push->pile_b;
	while (last != NULL && last->pivot == 1)
	{
		tmp = last->next;
		last->sorted = 1;
		make_move(push, "pa");
		last = tmp;
	}
//	sort_b(push);
	while (last != NULL && last->pivot == 0)
	{
		tmp = last->next;
		make_move(push, "pa");
		last = tmp;
	}
}