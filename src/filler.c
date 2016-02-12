/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 18:51:36 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/12 19:27:37 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_get_board(t_env *e)
{
	int		i;
	char	*str;
	char	**split;

	i = 0;
	ft_strdel(&(e->map));
	e->map = ft_strnew(0);
	while (i <= e->b_y)
	{
		get_next_line(0, &str);
		if (i != 0)
			e->map = ft_strjoin_free(e->map,
				(split = ft_strsplit(str, ' '))[1]);
		i++;
	}
}

static void	ft_get_piece(t_env *e)
{
	char	*str;
	int		i;

	i = 0;
	ft_strdel(&(e->piece));
	while (i < e->p_y)
	{
		get_next_line(0, &str);
		e->piece = ft_strjoin_free(e->piece, str);
		i++;
	}
	ft_ai(e);
}

static void	ft_get_map(t_env *e)
{
	char	*str;
	char	**split;

	while (get_next_line(0, &str))
	{
		if (ft_strncmp(str, "$$$ exec p1 : [./filler", 23) == 0)
			e->letter = 'O';
		else if (ft_strncmp(str, "$$$ exec p2 : [./filler", 23) == 0)
			e->letter = 'X';
		if (ft_strncmp(str, "Plateau", 7) == 0)
		{
			split = ft_strsplit(str, ' ');
			e->b_y = ft_atoi(split[1]);
			e->b_x = ft_atoi(split[2]);
			ft_get_board(e);
		}
		else if (ft_strncmp(str, "Piece", 5) == 0)
		{
			split = ft_strsplit(str, ' ');
			e->p_y = ft_atoi(split[1]);
			e->p_x = ft_atoi(split[2]);
			ft_get_piece(e);
		}
	}
}

int			main(void)
{
	t_env env;

	env.letter = 'O';
	ft_get_map(&env);
	return (0);
}
