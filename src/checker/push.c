/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <Raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 00:46:31 by ratin             #+#    #+#             */
/*   Updated: 2019/07/04 06:02:45 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		transfer_elem(t_push *push, t_pile **src, t_pile **dst)
{
	t_pile	*cpy;
	t_pile	*tmp;

	cpy = create_elem(push, (*src)->nbr);
	cpy->sorted = (*src)->sorted;
	if ((*dst) != NULL)
		(*dst)->prev = cpy;
	cpy->next = (*dst);
	(*dst) = cpy;
	tmp = (*src)->next;
	free(*src);
	(*src) = tmp;
}

void		replace_prev(t_push *push)
{
	t_pile	*current;

	current = push->pile_a;
	current->prev = NULL;
	while (current && current->next)
	{
		current->next->prev = current;
		current = current->next;
	}
	current = push->pile_b;
	while (current && current->next)
	{
		current->next->prev = current;
		current = current->next;
	}
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
