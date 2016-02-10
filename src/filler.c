#include "filler.h"

#include <stdio.h>

static int	ft_test_placement(int i, int n, t_env *e)
{
	int x_center;
	int y_center;
	int x_i;
	int y_i;
	int x_pos;
	int y_pos;
	int	c;
	int	touch;
	char	pos_content;

	touch = 0;
	x_center = n % e->p_x;
	y_center = n / e->p_x;
	x_i = i % e->b_x;
	y_i = i / e->b_x;

	c = 0;
/*	ft_putstr_fd("I == ", 2);
	ft_putnbr_fd(i, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("N == ", 2);
	ft_putnbr_fd(n, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("N center X == ", 2);
	ft_putnbr_fd(x_center, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("N center Y == ", 2);
	ft_putnbr_fd(y_center, 2);
	ft_putchar_fd('\n', 2);*/
	while ((e->piece)[c])
	{
		if ((e->piece)[c] == '*')
		{
			x_pos = x_i + ((c % e->p_x) - x_center);
			y_pos = y_i + ((c / e->p_x) - y_center);
/*			ft_putstr_fd("___________________________", 2);
			ft_putchar_fd('\n', 2);
			ft_putstr_fd("pos of each *:\nY:  ", 2);
			ft_putnbr_fd(y_pos, 2);
			ft_putchar_fd('\n', 2);
			ft_putstr_fd("pos of each *:\nX:  ", 2);
			ft_putnbr_fd(x_pos, 2);
			ft_putchar_fd('\n', 2);
			ft_putstr_fd("CONTENT POS in grid *:\n:  ", 2);
			ft_putnbr_fd((y_pos * e->b_x) + x_pos, 2);
			ft_putchar_fd('\n', 2);*/
			if ((y_pos * e->b_x) + x_pos < 0)
				return (0);
			if ((pos_content = (e->map)[(y_pos * e->b_x) + x_pos]) != '.')
			{
				if (pos_content == e->letter)
				{
					touch++;
					if (touch > 1)
						return (0);
				}
				else
					return (0);
			}

		}
		c++;
	}

/*	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(x_center, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(y_center, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);*/
	return (1);
}

static void	ft_ai(t_env *e)
{
	int x_b = 0;
	int y_b = 0;
	int x_p = 0;
	int y_p = 0;
	int	i;
	int	n;
	int	x;
	int	y;
	int ret;

	i = 0;
	ret = -1;
	while ((e->map)[i])
	{
		if ((e->map)[i] == e->letter)
		{
			n = 0;
			while ((e->piece)[n])
			{
				if ((e->piece)[n] == '*')
				{
					x_p = n % e->p_x;
					y_p = n / e->p_x;

					x_b = i % e->b_x;
					y_b = i / e->b_x;
					
				/*	ft_putstr_fd("PIECE:\nX:  ", 2);
					ft_putstr_fd(e->piece, 2);
					ft_putchar_fd('\n', 2);*/
					/*ft_putstr_fd("n offset:\nX:  ", 2);
					ft_putnbr_fd(x_p, 2);
					ft_putchar_fd('\n', 2);
					ft_putstr_fd("n offset:\nY:  ", 2);
					ft_putnbr_fd(y_p, 2);
					ft_putchar_fd('\n', 2);
					ft_putstr_fd("WIDTH:\n  ", 2);
					ft_putnbr_fd(e->p_x, 2);
					ft_putchar_fd('\n', 2);
					ft_putstr_fd("HEIGHT:\n  ", 2);
					ft_putnbr_fd(e->p_y, 2);
					ft_putchar_fd('\n', 2);*/
					if ((ret = ft_test_placement(i, n, e)) == 1)
						break ;
				}
				n++;
			}
			if (ret == 1)
				break ;
		}
		i++;
	}
/*	ft_putstr_fd("n offset:\nX:  ", 2);
	ft_putnbr_fd(x_p, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("n offset:\nY:  ", 2);
	ft_putnbr_fd(y_p, 2);
	ft_putchar_fd('\n', 2);*/
/*	ft_putstr_fd("X_B:\n ", 2);
	ft_putnbr_fd(x_b, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("Y_B\n  ", 2);
	ft_putnbr_fd(y_b, 2);
	ft_putchar_fd('\n', 2);
	*/
	x = x_b - x_p;
	y = y_b - y_p;
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

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
		{
			e->map = ft_strjoin_free(e->map, (split = ft_strsplit(str, ' '))[1]);
		}
		i++;
	}
	/*ft_putstr_fd("BOARD: ", 2);
	ft_putstr_fd(e->map, 2);
	ft_putchar_fd('\n', 2);*/
}

static void	ft_get_piece(t_env *e)
{
	char *str;
	int	i;

	i = 0;
	ft_strdel(&(e->piece));
	while (i < e->p_y)
	{
		get_next_line(0, &str);
		e->piece = ft_strjoin_free(e->piece, str);
		i++;
	}
	ft_ai(e);
	/*ft_putstr_fd("PIECE: ", 2);
	ft_putstr_fd(e->piece, 2);
	ft_putchar_fd('\n', 2);*/
	//ft_putstr("1 7\n");
}

static void	ft_get_map(t_env *e)
{
	char	*str;
	char	**split;

	while (get_next_line(0, &str))
	{
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

int	main(void)
{
	t_env env;

	env.letter = 'O'; // have to change dat later
	ft_get_map(&env);
	return (0);
}
