/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:17:31 by aptive            #+#    #+#             */
/*   Updated: 2022/02/16 19:42:05 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_life.h"

int	render_next_frame(t_data *vars)
{
	int i;
	i = 0;
	if(vars->begin)
	{
		ft_rules(vars->tab_coord);
		while (vars->tab_coord[i])
		{
			if (vars->tab_coord[i]->full == 1)
				ft_full(*vars, *vars->tab_coord[i]);
			else
				ft_empty(*vars, *vars->tab_coord[i]);
			i++;
		}
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, 0, 0);
	}
	usleep(300000);
	return (1);
}

int	main()
{
	t_coord *(*tab_coord);
	t_data	vars;
	int	i;

	(void) tab_coord;
	(void) i;
	vars.begin = 0;
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, WIDTH_SCREEN, HEIGHT_SCREEN, "Game Life");
	vars.img = mlx_new_image(vars.mlx, WIDTH_SCREEN, HEIGHT_SCREEN);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length,&vars.endian);

	ft_grille(vars);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, 0, 0);

	tab_coord = NULL;
	tab_coord = ft_init_point(tab_coord);
	vars.tab_coord = tab_coord;
	i = 0;
/*
	vars.tab_coord[2619 + LINE]->full = 1;
		ft_full(vars, *vars.tab_coord[2619 + LINE ]);
	vars.tab_coord[2619]->full = 1;
		ft_full(vars, *vars.tab_coord[2619]);

	vars.tab_coord[2619 + LINE + 1]->full = 1;
		ft_full(vars, *vars.tab_coord[2619 + LINE + 1]);

	vars.tab_coord[2619 + LINE - 1]->full = 1;
		ft_full(vars, *vars.tab_coord[2619 + LINE - 1]);

	vars.tab_coord[2619 + LINE * 2 - 1]->full = 1;
		ft_full(vars, *vars.tab_coord[2619 + LINE * 2 - 1]);
*/
	while ( i <= 15)
	{
		vars.tab_coord[2619 + LINE * i]->full = 1;
		ft_full(vars, *vars.tab_coord[2619 + LINE * i]);
		vars.tab_coord[2619 - LINE + i]->full = 1;
		ft_full(vars, *vars.tab_coord[2619 - LINE * i]);
		i++;
	}
/*
	while (i < 10)
	{
		vars.tab_coord[2592 + 27 + i]->full = 1;
		ft_full(vars, *vars.tab_coord[2592 + 27 + i]);
		i++;
	}*/
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, 0, 0);
	sleep(5);


	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	printf("begin : %d\n", vars.begin);

	mlx_loop_hook(vars.mlx, render_next_frame, &vars);

	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
int	ft_close(int keycode, t_data *vars)
{
	(void) keycode;
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(1);
	return (0);
}

int	key_hook(int keycode, t_data *vars)
{
	(void)vars;
	if (keycode == 53)
		ft_close(keycode, vars);
	if (keycode == 49 && vars->begin == 0)
		vars->begin = 1;
	else if (keycode == 49 && vars->begin == 1)
		vars->begin = 0;
	printf("key = %d\n",keycode);

	return (1);
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
		}
		i++;
	}
	tab_coord[size] = NULL;
	return (tab_coord);
}

