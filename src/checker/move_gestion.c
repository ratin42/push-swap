/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_gestion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <Raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 04:01:03 by ratin             #+#    #+#             */
/*   Updated: 2019/06/22 22:06:39 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		make_move_3(t_push *push, char *str)
{
	if (ft_strcmp(str, "rra") == 0)
	{
		reverse_rotate(push, 'a');
		ft_putstr("rra\n");
	}
	if (ft_strcmp(str, "rrb") == 0)
	{
		reverse_rotate(push, 'b');
		ft_putstr("rrb\n");
	}
	if (ft_strcmp(str, "rrr") == 0)
	{
		reverse_reverse(push);
		ft_putstr("rrr\n");
	}
}

void		make_move_2(t_push *push, char *str)
{
	if (ft_strcmp(str, "pb") == 0)
	{
		push_move(push, 'b');
		ft_putstr("pb\n");
	}
	if (ft_strcmp(str, "ra") == 0)
	{
		rotate(push, 'a');
		ft_putstr("ra\n");
	}
	if (ft_strcmp(str, "rb") == 0)
	{
		rotate(push, 'b');
		ft_putstr("rb\n");
	}
	if (ft_strcmp(str, "rr") == 0)
	{
		rotate_rotate(push);
		ft_putstr("rr\n");
	}
	make_move_3(push, str);
}

void		make_move(t_push *push, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
	{
		swap(push, 'a');
		ft_putstr("sa\n");
	}
	if (ft_strcmp(str, "sb") == 0)
	{
		swap(push, 'b');
		ft_putstr("sb\n");
	}
	if (ft_strcmp(str, "ss") == 0)
	{
		swap_swap(push);
		ft_putstr("ss\n");
	}
	if (ft_strcmp(str, "pa") == 0)
	{
		push_move(push, 'a');
		ft_putstr("pa\n");
	}
	make_move_2(push, str);
}

void		check_output(t_push *push, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		return ;
	if (ft_strcmp(str, "sb") == 0)
		return ;
	if (ft_strcmp(str, "ss") == 0)
		return ;
	if (ft_strcmp(str, "pa") == 0)
		return ;
	if (ft_strcmp(str, "pb") == 0)
		return ;
	if (ft_strcmp(str, "ra") == 0)
		return ;
	if (ft_strcmp(str, "rb") == 0)
		return ;
	if (ft_strcmp(str, "rr") == 0)
		return ;
	if (ft_strcmp(str, "rra") == 0)
		return ;
	if (ft_strcmp(str, "rrb") == 0)
		return ;
	if (ft_strcmp(str, "rrr") == 0)
		return ;
	free(str);
	ft_putstr("Error\n");
	quit_prog(push);
}

void		get_output(t_push *push)
{
	char	*str;

	str = NULL;
	while (get_next_line(0, &str) == 1)
	{
		check_output(push, str);
		make_move(push, str);
		free(str);
	}
	if (str == NULL)
	{
		ft_putstr("Error\n");
		quit_prog(push);
	}
}
