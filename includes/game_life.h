/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_life.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:17:29 by aptive            #+#    #+#             */
/*   Updated: 2022/02/15 19:27:52 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_LIFE_H
#define GAME_LIFE_H

# include "../libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "../miniLibX_X11/mlx.h"

# define	WIDTH_SCREEN	1920
# define	HEIGHT_SCREEN	1080

# define	GREEN 0xFF043C00
# define	GREEN_LIGHT 0xFF0ECD00

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_coordonnees {
	int	x_pt;
	int	y_pt;
	int	full;
}				t_coord;
/*
FT_GAME_LIFE_C ------------------------------------------------------------------
*/

int		render_next_frame(t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_lign_horizontal(t_data vars, int x, int x_end, int y, int color);
void	ft_lign_vertical(t_data img, int x, int y, int y_end, int color);

t_coord	**ft_init_point(t_coord *(*tab_coord));
void	ft_full(t_data vars, t_coord point);

#endif
