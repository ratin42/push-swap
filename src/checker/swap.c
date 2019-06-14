/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 00:14:59 by ratin             #+#    #+#             */
/*   Updated: 2019/06/04 00:51:03 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_list_swap(t_pile *pile1, t_pile *pile2)
{
	int		tmp;

	tmp = pile1->nbr;
	pile1->nbr = pile2->nbr;
	pile2->nbr = tmp;
}

void		swap(t_push *push, char pile)
{
	t_pile	*element;

	if (pile == 'a' && push->pile_a != NULL && push->pile_a->next != NULL)
		element = push->pile_a;
	else if (push->pile_b != NULL && push->pile_b->next != NULL)
		element = push->pile_b;
	else
		return ;
	ft_list_swap(element, element->next);
}

void		swap_swap(t_push *push)
{
	swap(push, 'a');
	swap(push, 'b');
}
