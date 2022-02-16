/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:17:31 by aptive            #+#    #+#             */
/*   Updated: 2022/02/15 20:15:47 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_life.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_lign_vertical(t_data vars, int x, int y, int y_end, int color)
{
	while (y < y_end)
	{
		my_mlx_pixel_put(&vars, x, y, color);
		y++;
	}
}

void	ft_lign_horizontal(t_data vars, int x, int x_end, int y,int color)
{
	while (x < x_end)
	{
		my_mlx_pixel_put(&vars, x, y, color);
		x++;
	}
}

int	render_next_frame(t_data *img)
{
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (1);
}

int	main()
{
	t_coord *(*tab_coord);
	t_data	vars;
	int	i;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, WIDTH_SCREEN, HEIGHT_SCREEN, "Game Life");
	vars.img = mlx_new_image(vars.mlx, WIDTH_SCREEN, HEIGHT_SCREEN);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length,&vars.endian);

	i = 0;
	while (i <= WIDTH_SCREEN)
	{
		ft_lign_vertical(vars, i, 0, HEIGHT_SCREEN, GREEN);
		i = i + 20;
	}
	i = 0;
	while (i <= HEIGHT_SCREEN)
	{
		ft_lign_horizontal(vars, 0, WIDTH_SCREEN, i, GREEN);
		i = i + 20;
	}
	tab_coord = NULL;
	printf("taille : %d\n", (HEIGHT_SCREEN / 20) * (WIDTH_SCREEN / 20));
	tab_coord = ft_init_point(tab_coord);
	int z = 2500;
	tab_coord[z]->full = 1;

	tab_coord[z - 1]->full = 1;
	tab_coord[z + 1]->full = 1;
	tab_coord[z + 54]->full = 1;
	tab_coord[z - 54]->full = 1;
	tab_coord[z + 54 + 1]->full = 1;
	tab_coord[z + 54 - 1]->full = 1;
	tab_coord[z - 54 + 1]->full = 1;
	tab_coord[z - 54 - 1]->full = 1;
	i = 0;
	while (tab_coord[i])
	{
		if(tab_coord[i]->full == 1)
			ft_full(vars, *tab_coord[i]);
		i++;
	}
	//ft_full(vars, *tab_coord[1]);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, 0, 0);
	mlx_loop(vars.mlx);

	printf("ok\n");

	return (0);
}

t_coord	**ft_init_point(t_coord *(*tab_coord))
{
	int	size;
	int	i;
	int	j;
	int k;

	i = 0;
	k = 0;
	size = (HEIGHT_SCREEN / 20) * (WIDTH_SCREEN / 20);
	tab_coord = malloc(sizeof(tab_coord) * (size + 1));
	if (!tab_coord)
		return (NULL);
	while (i * 20 < WIDTH_SCREEN)
	{
		j = 0;
		while (j * 20 < HEIGHT_SCREEN)
		{
			tab_coord[k] = malloc(sizeof(t_coord));
			tab_coord[k]->x_pt = i;
			tab_coord[k]->y_pt = j;
			tab_coord[k]->full = 0;
			j++;
			k++;
			//printf("k : %d\n", k);
		}
		i++;
		//printf("i : %d\n", i);
	}
/*	printf("test x_pt : %d\n",tab_coord[40]->x_pt);
	printf("test y_pt : %d\n",tab_coord[40]->y_pt);
	printf("test full : %d\n",tab_coord[40]->full);
*/	tab_coord[size] = NULL;
	return (tab_coord);
}

void	ft_full(t_data vars, t_coord point)
{
	int	x_beg;
	int	x_end;

	int	y_beg;
	int	y_end;

	int	x_actual;

	x_beg = 20 * point.x_pt;
	x_end = 20 * (point.x_pt + 1);

	y_beg = 20 * point.y_pt;
	y_end = 20 * (point.y_pt + 1);
	printf("x_beg : %d\n", x_beg);
	printf("x_end : %d\n", x_end);

	printf("y_beg : %d\n", y_beg);
	printf("y_end : %d\n", y_end);
	x_actual = x_beg + 1;
	while (x_actual < x_end)
	{
		ft_lign_vertical(vars, x_actual, y_beg, y_end, GREEN_LIGHT);
		x_actual++;
	}
}
