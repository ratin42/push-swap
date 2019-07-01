/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_sort_replace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <Raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:36:34 by Raphael           #+#    #+#             */
/*   Updated: 2019/06/28 17:36:21 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_prev_nbr(t_push *push, t_pile *element)
{
	if (element->prev == NULL)
		return (get_last(push, 'a'));
	return (element->prev->nbr);
}

/* static int	get_median(t_push *push)
{
	t_pile	*element;
	int		len;
	int		median;

	element = push->pile_a;
	len = len_pile(push, 'a');
	median = 0;
	while (element && median < len / 2)
	{
		element = element->next;
		median++;
	}
	return (element->nbr);
} */

void		rotate_placement(t_push *push)
{
	t_pile	*last;
	int		first;
	int		nbr;

	nbr = push->pile_b->nbr;
	last = push->pile_a;
	first = last->nbr;
	while (nbr > last->nbr)
	{
		print_pile(push);
		printf("nbr = %d et last = %d prev = %d\n", nbr, last->nbr, get_prev_nbr(push, last));
		if (get_prev_nbr(push, last) > last->nbr)
			break ;
		last = last->next;
		if (last->next->nbr == first || last->next->nbr > nbr)
			break ;
		make_move(push, "ra");
	}
	last = push->pile_a;
	while (last->prev->nbr > nbr)
	{
		last = last->prev;
		if (last->prev->nbr == first || last->prev->nbr < nbr)
			break ;
		make_move(push, "rra");
	}
}

//faire bouger la pile a avant de push a
//checker le nombre d'avant et le nombre d'apres pour pouvoir push sans revese
//optionellement chercher dans b le nombre le plus proche de premier nombre
//de a afin de reduire le nombre d'operation sur a
void		mid_sort_replace(t_push *push)
{
	t_pile	*element;
	//int		first;
	//int		step;

	printf("entree\n");
	element = push->pile_a;
	//if (push->pile_b < get_median(push))
	rotate_placement(push);
	make_move(push, "pa");

	printf("passage\n");
}
