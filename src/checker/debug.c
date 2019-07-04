/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <Raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 23:10:41 by ratin             #+#    #+#             */
/*   Updated: 2019/07/04 06:02:33 by Raphael          ###   ########.fr       */
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
		printf("%d srtd = %d", last->nbr, last->sorted);
		last = last->next;
	}
	last = push->pile_b;
	printf("\nprint------ pile b:\n");
	while (last)
	{
		printf("%d srtd = %d", last->nbr, last->sorted);
		last = last->next;
	}
}
