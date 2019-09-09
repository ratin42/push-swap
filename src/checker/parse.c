/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 02:10:53 by ratin             #+#    #+#             */
/*   Updated: 2019/07/23 20:30:29 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		quit_prog(t_push *push)
{
	free_pile(push);
	exit(1);
}

static int	check_error(int ac, char **av)
{
	int	i;
	int	str_i;

	i = 1;
	while (i < ac)
	{
		str_i = 0;
		while (av[i][str_i])
		{
			if (ft_strchr("+- 0123456789", av[i][str_i]) == NULL)
				return (ERROR);
			str_i++;
		}
		i++;
	}
	return (SUCCESS);
}

void		check_presence(t_push *push, int nbr)
{
	t_pile	*last;

	last = push->pile_a;
	while (last)
	{
		if (last->nbr == nbr)
		{
			ft_putstr("Error\n");
			quit_prog(push);
		}
		last = last->next;
	}
}

int			parse_input(t_push *push, int ac, char **av)
{
	int		i;
	int		arg_i;
	char	**arg;

	i = 1;
	if (check_error(ac, av) == ERROR)
		return (ERROR);
	while (i < ac)
	{
//		if (detect_int_limit(av[i]) == ERROR)
//			return (ERROR);
		arg = ft_strsplit(av[i], ' ');
		arg_i = 0;
		while (arg[arg_i])
		{
			if (arg[arg_i][0] == '+')
			{
				ft_putstr("Error\n");
				quit_prog(push);
			}
			check_presence(push, ft_atoi(arg[arg_i]));
			add_elem(push, ft_atoi(arg[arg_i]));
			arg_i++;
		}
		i++;
		free_double_char(arg);
	}
	return (SUCCESS);
}
