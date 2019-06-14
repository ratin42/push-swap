/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 00:43:03 by ratin             #+#    #+#             */
/*   Updated: 2019/06/08 03:05:49 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "struct.h"
# include "../libft/includes/libft.h"

# define ERROR		-1
# define SUCCESS	1

# include <stdio.h>

/*
** move function
*/
void	get_output(t_push *push);
void	make_move(t_push *push, char *str);
void	swap(t_push *push, char pile);
void	swap_swap(t_push *push);
void	push_move(t_push *push, char pile);
void	rotate(t_push *push, char pile);
void	rotate_rotate(t_push *push);
void	reverse_rotate(t_push *push, char pile);
void	reverse_reverse(t_push *push);

/*
** pile function
*/
void	free_pile(t_push *push);
void	sort_pile(t_push *push);
void	add_elem(t_push *push, int nbr);
int		len_pile(t_push *push, char pile);
int		len_pile_sorted(t_push *push, char pile);

int		parse_input(t_push *push, int ac, char **av);
void	free_double_char(char **array);
void	check_output(t_push *push, char *str);
void	quit_prog(t_push *push);
void	do_sort(t_push *push);
int		put_pivot(t_push *push, char pile);
void	working_stack_a(t_push *push);
void	working_stack_b(t_push *push);

/*
** DEBUG
*/
void	print_pile(t_push *push);
#endif