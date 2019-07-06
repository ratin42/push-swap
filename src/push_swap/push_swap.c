/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 00:56:08 by ratin             #+#    #+#             */
/*   Updated: 2019/07/06 02:34:08 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		init_push(t_push *push)
{
	push->pile_a = NULL;
	push->pile_b = NULL;
}

int			main(int ac, char **av)
{
	t_push	push;

	if (ac == 1)
		exit(ERROR);
	init_push(&push);
	if (parse_input(&push, ac, av) == ERROR)
		return (ERROR);
	sort_pile(&push);
	free_pile(&push);
	return (0);
}
