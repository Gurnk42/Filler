#include "filler.h"

int		ft_test_placement(int i, int n, t_env *e)
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
	while ((e->piece)[c])
	{
		if ((e->piece)[c] == '*')
		{
			x_pos = x_i + ((c % e->p_x) - x_center);
			y_pos = y_i + ((c / e->p_x) - y_center);
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
	return (1);
}

void	ft_ai(t_env *e)
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
					if (((ret = ft_test_placement(i, n, e)) == 1)
							&& ((x_b - x_p) >= 0)
							&& ((y_b - y_p) >= 0))
						break ;
					else
						ret = 0;
				}
				n++;
			}
			if (ret == 1)
				break ;
		}
		i++;
	}
	x = x_b - x_p;
	y = y_b - y_p;
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}
