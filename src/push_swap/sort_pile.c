/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <Raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 04:40:25 by ratin             #+#    #+#             */
/*   Updated: 2019/07/04 06:05:35 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_pile(t_push *push)
{
	if (len_pile(push, 'a') == 3)
		do_little_sort(push);
	else if (len_pile(push, 'a') == 2
	&& push->pile_a->nbr > push->pile_a->next->nbr)
		make_move(push, "sa");
	else
		do_mid_sort(push);
	//print_pile(push);
}