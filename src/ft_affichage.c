/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:42:19 by tdelauna          #+#    #+#             */
/*   Updated: 2022/02/16 18:22:50 by tdelauna         ###   ########.fr       */
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

void	ft_full(t_data vars, t_coord point)
{
	int	x_end;
	int	y_beg;
	int	y_end;
	int	x_actual;

	x_actual = 20 * point.x_pt + 1;
	x_end = 20 * (point.x_pt + 1);
	y_beg = 20 * point.y_pt;
	y_end = 20 * (point.y_pt + 1);
	while (x_actual < x_end)
	{
		ft_lign_vertical(vars, x_actual, y_beg + 1, y_end, GREEN_LIGHT);
		x_actual++;
	}
}
void	ft_empty(t_data vars, t_coord point)
{
	int	x_end;
	int	y_beg;
	int	y_end;
	int	x_actual;

	x_actual = 20 * point.x_pt + 1;
	x_end = 20 * (point.x_pt + 1);
	y_beg = 20 * point.y_pt;
	y_end = 20 * (point.y_pt + 1);
	while (x_actual < x_end)
	{
		ft_lign_vertical(vars, x_actual, y_beg + 1, y_end, BLACK);
		x_actual++;
	}
}

void ft_grille(t_data vars)
{
	int i;

	i = 0;
	while (i < WIDTH_SCREEN)
	{
		ft_lign_vertical(vars, i, 0, HEIGHT_SCREEN, GREEN);
		if (i < HEIGHT_SCREEN)
			ft_lign_horizontal(vars, 0, WIDTH_SCREEN, i, GREEN);
		i = i + 20;
	}
}
