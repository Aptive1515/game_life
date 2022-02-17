/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:41:21 by tdelauna          #+#    #+#             */
/*   Updated: 2022/02/17 16:12:16 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_life.h"

int	key_hook(int keycode, t_data *vars)
{
	(void)vars;
	if (keycode == 53)
		ft_close(keycode, vars);
	if (keycode == 49 && vars->begin == 0)
		vars->begin = 1;
	else if (keycode == 49 && vars->begin == 1)
		vars->begin = 0;
	else if (keycode == 8)
		ft_clean(vars);
	else if (keycode == 18)
		ft_one(vars);
	else if (keycode == 19)
		ft_two(vars);
	else if (keycode == 20)
		ft_three(vars);
	else if (keycode == 21)
		ft_four(vars);
	/*else if (keycode == 23)
	else if (keycode == 22)
	else if (keycode == 26)
	else if (keycode == 28)
	else if (keycode == 25)
	else if (keycode == 29)*/

	printf("key = %d\n",keycode);

	return (1);
}

int	ft_clean(t_data *vars)
{
	int i;

	i = 0;
	while (vars->tab_coord[i])
	{
		vars->tab_coord[i]->full = 0;
		vars->tab_coord[i]->full_next = 0;
		ft_empty(*vars, *vars->tab_coord[i]);
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, 0, 0);
	vars->begin = 0;
	return (1);
}

int	ft_close(int keycode, t_data *vars)
{
	(void) keycode;
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(1);
	return (0);
}
