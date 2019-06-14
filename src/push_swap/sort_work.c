/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 04:51:14 by ratin             #+#    #+#             */
/*   Updated: 2019/06/09 10:21:25 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_sort(t_push *push)
{
	t_pile	*last;

	last = push->pile_a;
	while (last->next)
	{
		if (last->nbr > last->next->nbr)
			return (0);
		last = last->next;
	}
	if (push->pile_b != NULL)
		return (0);
	return (1);
}

void		do_sort(t_push *push)
{
	//for (int i = 0; i < 2; i++)
	while (check_sort(push) == 0)
	{
		working_stack_a(push);
		print_pile(push);
		working_stack_b(push);
	}
}