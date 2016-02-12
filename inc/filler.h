#ifndef FILLER_H
# define FILLER_H
# include "get_next_line.h"
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
int		ft_test_placement(int i, int n, t_env *e);
void	ft_ai(t_env *e);


#endif
