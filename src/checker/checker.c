/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 00:49:08 by ratin             #+#    #+#             */
/*   Updated: 2019/07/16 19:37:40 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		init_push(t_push *push)
{
	push->pile_a = NULL;
	push->pile_b = NULL;
}

void		check_order(t_push *push)
{
	t_pile	*last;

	last = push->pile_a;
	while (last->next)
	{
		if (last->next != NULL && last->next->nbr < last->nbr)
		{
			ft_putstr("KO\n");
			return ;
		}
		last = last->next;
	}
	if (push->pile_b == NULL)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int			main(int ac, char **av)
{
	t_push	push;

	if (ac == 1)
		exit(ERROR);
	init_push(&push);
	if (parse_input(&push, ac, av) == ERROR)
	{
		ft_putstr("Error\n");
		return (ERROR);
	}
	get_output(&push);
	check_order(&push);
	return (0);
}
