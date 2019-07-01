/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <Raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 00:46:31 by ratin             #+#    #+#             */
/*   Updated: 2019/06/28 17:50:03 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		transfer_elem(t_push *push, t_pile **src, t_pile **dst)
{
	t_pile *tmp;

	tmp = (*dst);
	(*dst) = (*src);
	(*src) = (*src)->next;
	(*src)->prev = NULL;
	(*dst)->next = tmp;
	//printf("passage tmp = %d\n", tmp->nbr);
	(*dst)->prev = NULL;
	(void)tmp;
	(void)dst;
	(void)push;
}

void		push_move(t_push *push, char pile)
{
	t_pile	**src;
	t_pile	**dst;

	if (pile == 'a')
	{
		if (push->pile_b == NULL)
			return ;
		src = &push->pile_b;
		dst = &push->pile_a;
	}
	else
	{
		if (push->pile_a == NULL)
			return ;
		src = &push->pile_a;
		dst = &push->pile_b;
	}
	transfer_elem(push, src, dst);
}
