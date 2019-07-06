/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 03:30:33 by ratin             #+#    #+#             */
/*   Updated: 2019/07/06 02:33:56 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_double_char(char **array)
{
	int i;

	i = 0;
	while (array[i] != 0)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void		free_pile(t_push *push)
{
	t_pile	*last;
	t_pile	*tmp;

	last = push->pile_a;
	while (last)
	{
		tmp = last->next;
		free(last);
		last = tmp;
	}
	last = push->pile_b;
	while (last)
	{
		tmp = last->next;
		free(last);
		last = tmp;
	}
}
