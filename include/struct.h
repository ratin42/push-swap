/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 00:46:59 by ratin             #+#    #+#             */
/*   Updated: 2019/06/08 01:58:05 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_output
{
	char			*instruction;
	struct s_output	*next;
	struct s_output	*prev;
}					t_output;

typedef struct		s_push_swap
{
	struct s_pile	*pile_a;
	struct s_pile	*pile_b;
	int				test;
}					t_push;

typedef struct		s_pile
{
	int				nbr;
	int				pivot;
	int				sorted;
	struct s_pile	*next;
	struct s_pile	*prev;
}					t_pile;

#endif
