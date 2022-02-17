/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:59:01 by tdelauna          #+#    #+#             */
/*   Updated: 2022/02/17 16:26:07 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_life.h"

void	ft_put_full(t_data *vars)
{
	int	i;

	i = 0;
	while (vars->tab_coord[i])
	{
		if (vars->tab_coord[i]->full == 1)
			ft_full(*vars, *vars->tab_coord[i]);
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, 0, 0);
}

void	ft_one(t_data *vars)
{
	int	nb;

	ft_clean(vars);
	nb = 2500;
	vars->tab_coord[nb]->full = 1;
	vars->tab_coord[nb - 1]->full = 1;
	vars->tab_coord[nb + 1]->full = 1;
	vars->tab_coord[nb + LINE]->full = 0;
	vars->tab_coord[nb - LINE]->full = 1;
	vars->tab_coord[nb + LINE + 1]->full = 1;
	ft_put_full(vars);
}

void	ft_two(t_data *vars)
{
	int	nb;

	ft_clean(vars);
	nb = 2500;
	vars->tab_coord[nb]->full = 1;
	vars->tab_coord[nb - 1]->full = 1;
	vars->tab_coord[nb + 1]->full = 1;
	ft_put_full(vars);
}

void	ft_three(t_data *vars)
{
	int	nb;
	int i;

	nb = 2500;
	i = 0;
	ft_clean(vars);
	while (i <= 10)
	{
		vars->tab_coord[nb + LINE * i]->full = 1;
		i++;
	}
	ft_put_full(vars);
}

void	ft_four(t_data *vars)
{
	int	nb;

	ft_clean(vars);
	nb = 2500;
// 1st square -----------------------------
	vars->tab_coord[nb + LINE * -2]->full = 1;
	vars->tab_coord[nb + LINE * -2 + 1]->full = 1;
	vars->tab_coord[nb + LINE * -1]->full = 1;
	vars->tab_coord[nb + LINE * -1 + 1]->full = 1;

// 1st form -------------------------------
	vars->tab_coord[nb + LINE * 8]->full = 1;
	vars->tab_coord[nb + LINE * 8 + 1]->full = 1;
	vars->tab_coord[nb + LINE * 8 + 2]->full = 1;

	vars->tab_coord[nb + LINE * 9 - 1]->full = 1;
	vars->tab_coord[nb + LINE * 9 + 3]->full = 1;

	vars->tab_coord[nb + LINE * 10 - 2]->full = 1;
	vars->tab_coord[nb + LINE * 10 + 4]->full = 1;

	vars->tab_coord[nb + LINE * 11 - 2]->full = 1;
	vars->tab_coord[nb + LINE * 11 + 4]->full = 1;

	vars->tab_coord[nb + LINE * 12 + 1]->full = 1;

	vars->tab_coord[nb + LINE * 13 - 1]->full = 1;
	vars->tab_coord[nb + LINE * 13 + 3]->full = 1;

	vars->tab_coord[nb + LINE * 14]->full = 1;
	vars->tab_coord[nb + LINE * 14 + 1]->full = 1;
	vars->tab_coord[nb + LINE * 14 + 2]->full = 1;

	vars->tab_coord[nb + LINE * 15 + 1]->full = 1;
// 2nd form -------------------------------
	vars->tab_coord[nb + LINE * 18]->full = 1;
	vars->tab_coord[nb + LINE * 18 - 1]->full = 1;
	vars->tab_coord[nb + LINE * 18 - 2]->full = 1;

	vars->tab_coord[nb + LINE * 19]->full = 1;
	vars->tab_coord[nb + LINE * 19 - 1]->full = 1;
	vars->tab_coord[nb + LINE * 19 - 2]->full = 1;

	vars->tab_coord[nb + LINE * 20 - 3]->full = 1;
	vars->tab_coord[nb + LINE * 20 + 1]->full = 1;

	vars->tab_coord[nb + LINE * 22 - 3]->full = 1;
	vars->tab_coord[nb + LINE * 22 - 4]->full = 1;
	vars->tab_coord[nb + LINE * 22 + 1]->full = 1;
	vars->tab_coord[nb + LINE * 22 + 2]->full = 1;

// 2nd square

	vars->tab_coord[nb + LINE * 32 - 2]->full = 1;
	vars->tab_coord[nb + LINE * 32 - 1]->full = 1;
	vars->tab_coord[nb + LINE * 33 - 2]->full = 1;
	vars->tab_coord[nb + LINE * 33 - 1]->full = 1;
	ft_put_full(vars);
}
