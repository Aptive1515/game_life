/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:50:51 by aptive            #+#    #+#             */
/*   Updated: 2022/02/20 17:26:13 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_life.h"

int	ft_find_coord(int x, int y, t_coord *(*tab_coord))
{
	int	i;

	i = 0;
	while (tab_coord[i]->x_pt != x / 20 || tab_coord[i]->y_pt != y / 20)
		i++;
	return (i);
}

int	ft_put_cell(int nb, t_data *vars)
{
	vars->tab_coord[nb]->full = 1;
	ft_full(*vars, *vars->tab_coord[nb]);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, 0, 0);
	return (1);
}

int	ft_delete_cell(int nb, t_data *vars)
{
	vars->tab_coord[nb]->full = 0;
	ft_empty(*vars, *vars->tab_coord[nb]);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, 0, 0);
	return (1);
}

int	ft_mouse_hook(int keycode, int x, int y, t_data *vars)
{

	(void)vars;
	printf("x : %d / y : %d\n", vars->tab_coord[0]->x_pt, vars->tab_coord[0]->y_pt);
	if (keycode == 1)
		ft_put_cell(ft_find_coord(x, y, vars->tab_coord), vars);
	if (keycode == 3)
		ft_delete_cell(ft_find_coord(x, y, vars->tab_coord), vars);
	printf("keycode : %d\n", keycode);
	return (1);
}
