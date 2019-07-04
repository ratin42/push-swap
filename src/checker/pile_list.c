/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <Raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 22:53:26 by ratin             #+#    #+#             */
/*   Updated: 2019/07/04 06:01:56 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile		*create_elem(t_push *push, int nbr)
{
	t_pile	*new_elem;

	if (!(new_elem = malloc(sizeof(*new_elem))))
		quit_prog(push);
	new_elem->nbr = nbr;
	new_elem->sorted = 0;
	new_elem->next = NULL;
	new_elem->prev = NULL;
	return (new_elem);
}

void		add_elem(t_push *push, int nbr)
{
	t_pile	*new_elem;
	t_pile	*last;

	new_elem = create_elem(push, nbr);
	last = push->pile_a;
	if (push->pile_a == NULL)
		push->pile_a = new_elem;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new_elem;
		new_elem->prev = last;
	}
}

void		add_front_elem(t_push *push, int nbr)
{
	t_pile	*new_elem;
	t_pile	*last;

	new_elem = create_elem(push, nbr);
	last = push->pile_a;
	if (push->pile_a == NULL)
		push->pile_a = new_elem;
	else
	{
		push->pile_a = new_elem;
		new_elem->next = last;
	}
}

int			len_pile(t_push *push, char pile)
{
	t_pile	*last;
	int		len;

	len = 0;
	if (pile == 'a')
		last = push->pile_a;
	if (pile == 'b')
		last = push->pile_b;
	while (last)
	{
		len++;
		last = last->next;
	}
	return (len);
}

int			len_pile_sorted(t_push *push, char pile)
{
	t_pile	*last;
	int		len;

	len = 0;
	if (pile == 'a')
		last = push->pile_a;
	if (pile == 'b')
		last = push->pile_b;
	while (last)
	{
		if (last->sorted == 1)
		{
			last = last->next;
			continue ;
		}
		len++;
		last = last->next;
	}
	return (len);
}