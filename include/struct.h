/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 00:46:59 by ratin             #+#    #+#             */
/*   Updated: 2019/07/06 02:50:12 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_push_swap
{
	struct s_pile	*pile_a;
	struct s_pile	*pile_b;
	int				test;
}					t_push;

typedef struct		s_pile
{
	int				nbr;
	int				sorted;
	struct s_pile	*next;
	struct s_pile	*prev;
}					t_pile;

#endif
