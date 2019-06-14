/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 23:10:41 by ratin             #+#    #+#             */
/*   Updated: 2019/06/08 02:16:50 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_pile(t_push *push)
{
	t_pile	*last;

	last = push->pile_a;
	printf("\nprint------ pile a:\n");
	while (last)
	{
		printf("%d srtd = %d piv = %d\n", last->nbr, last->sorted, last->pivot);
		last = last->next;
	}
	last = push->pile_b;
	printf("\nprint------ pile b:\n");
	while (last)
	{
		printf("%d srtd = %d piv = %d\n", last->nbr, last->sorted, last->pivot);
		last = last->next;
	}
}
