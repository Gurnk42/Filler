/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 20:00:44 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/12 20:37:47 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_free_split(char **s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_strdel(s + i);
		i++;
	}
}

void	ft_get_vm_data(char **str, t_env *e)
{
	char	**split;

	split = NULL;
	if (ft_strncmp(*str, "Plateau", 7) == 0)
	{
		split = ft_strsplit(*str, ' ');
		e->b_y = ft_atoi(split[1]);
		e->b_x = ft_atoi(split[2]);
		ft_get_board(e);
		if (split != NULL)
			ft_free_split(&split);
	}
	else if (ft_strncmp(*str, "Piece", 5) == 0)
	{
		split = ft_strsplit(*str, ' ');
		e->p_y = ft_atoi(split[1]);
		e->p_x = ft_atoi(split[2]);
		ft_get_piece(e);
		if (split != NULL)
			ft_free_split(&split);
	}
}
