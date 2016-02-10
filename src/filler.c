#include "filler.h"

#include <stdio.h>

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

	i = 0;
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
					y_p = n / e->p_y;

					x_b = i % e->b_x;
					y_b = i / e->b_y - 1;
					ft_putchar_fd('\n', 2);
					ft_putnbr_fd(x_b, 2);
					ft_putchar_fd('\n', 2);
					ft_putnbr_fd(y_b, 2);
					break ;
				}
				n++;
			}
			break ;
		}
		i++;
	}
	x = x_p + x_b;
	y = y_p + y_b;
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
