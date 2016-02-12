/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 19:26:23 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/12 20:37:49 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"

typedef struct	s_env
{
	char	*map;
	char	*piece;
	int		b_x;
	int		b_y;
	int		p_x;
	int		p_y;
	char	letter;
}				t_env;

typedef struct	s_placement
{
	int		x_center;
	int		y_center;
	int		x_i;
	int		y_i;
	int		x_pos;
	int		y_pos;
	int		c;
	int		touch;
	char	pos_content;
}				t_placement;

typedef struct	s_ai
{
	int		x_b;
	int		y_b;
	int		x_p;
	int		y_p;
	int		i;
	int		n;
	int		x;
	int		y;
	int		ret;
}				t_ai;

/*
** ai.c
*/
int				ft_test_placement(int i, int n, t_env *e);
void			ft_free_split(char **s);
void			ft_ai(t_env *e);
void			ft_get_vm_data(char **str, t_env *e);
void			ft_get_board(t_env *e);
void			ft_get_piece(t_env *e);

#endif
