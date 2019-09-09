/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_int_limit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:23:50 by ratin             #+#    #+#             */
/*   Updated: 2019/07/16 19:05:14 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			free_return(char *end, char *begin)
{
	free(end);
	free(begin);
	return (ERROR);
}

static int	detect_int_max(char *nbr)
{
	char	*begin;
	char	*end;

	if (nbr[0] == '-')
		return (SUCCESS);
	if (ft_strlen(nbr) > 10)
		return (ERROR);
	if (ft_strlen(nbr) < 10)
		return (SUCCESS);
	if (ft_strlen(nbr) == 10)
	{
		begin = ft_strsub(nbr, 0, 9);
		if (ft_atoi(begin) > 214748364)
		{
			free(begin);
			return (ERROR);
		}
		end = ft_strsub(nbr, 9, 9);
		if (ft_atoi(begin) == 214748364 && ft_atoi(end) > 7)
			return (free_return(end, begin));
		free(end);
		free(begin);
	}
	return (SUCCESS);
}

static int	detect_int_min(char *nbr)
{
	char	*begin;
	char	*end;

	if (ft_strlen(nbr) > 11)
		return (ERROR);
	if (ft_strlen(nbr) < 11)
		return (SUCCESS);
	if (ft_strlen(nbr) == 11)
	{
		begin = ft_strsub(nbr, 0, 10);
		if (ft_atoi(begin) < -214748364)
		{
			free(begin);
			return (ERROR);
		}
		end = ft_strsub(nbr, 10, 10);
		if (ft_atoi(begin) == -214748364 && ft_atoi(end) > 8)
			return (free_return(end, begin));
		free(end);
		free(begin);
	}
	return (SUCCESS);
}

int			detect_int_limit(char *nbr)
{
	if (detect_int_max(nbr) == ERROR || detect_int_min(nbr) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
