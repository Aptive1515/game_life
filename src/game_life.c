/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:17:31 by aptive            #+#    #+#             */
/*   Updated: 2022/02/17 16:27:36 by tdelauna         ###   ########.fr       */
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
		ft_full_next(vars->tab_coord);
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
	usleep(50000);
	//vars->begin = 0;
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

	int nb = 2500;
	tab_coord[nb]->full = 1;
	tab_coord[nb - 1]->full = 1;
	tab_coord[nb + 1]->full = 1;
	tab_coord[nb + LINE]->full = 0;
	tab_coord[nb - LINE]->full = 1;
	tab_coord[nb + LINE + 1]->full = 1;
	/*tab_coord[nb + LINE - 1]->full = 1;
	tab_coord[nb - LINE + 1]->full = 1;
	tab_coord[nb - LINE - 1]->full = 1;*/

	i = 0;
	while (vars.tab_coord[i])
	{
		if (vars.tab_coord[i]->full == 1)
			ft_full(vars, *vars.tab_coord[i]);
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, 0, 0);



	mlx_key_hook(vars.mlx_win, key_hook, &vars);

	mlx_loop_hook(vars.mlx, render_next_frame, &vars);

	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, 0, 0);
	mlx_loop(vars.mlx);
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
			tab_coord[k]->full = 0;
			j++;
			k++;
		}
		i++;
	}
	tab_coord[size] = NULL;
	return (tab_coord);
}

