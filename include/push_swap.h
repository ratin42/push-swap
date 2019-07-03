/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <Raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 00:43:03 by ratin             #+#    #+#             */
/*   Updated: 2019/07/03 13:23:30 by Raphael          ###   ########.fr       */
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
void	replace_prev(t_push *push);

/*
** pile function
*/
void	free_pile(t_push *push);
void	sort_pile(t_push *push);
void	add_elem(t_push *push, int nbr);
int		len_pile(t_push *push, char pile);
int		len_pile_sorted(t_push *push, char pile);
int		get_last(t_push *push, char pile);
t_pile	*create_elem(t_push *push, int nbr);
void	move_first_top(t_push *push, t_pile *first);

int		parse_input(t_push *push, int ac, char **av);
void	do_little_sort(t_push *push);
void	do_mid_sort(t_push *push);
void	mid_sort_replace(t_push *push);
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
