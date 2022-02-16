/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_life.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:17:29 by aptive            #+#    #+#             */
/*   Updated: 2022/02/16 19:17:23 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_LIFE_H
#define GAME_LIFE_H

# include "../libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <mlx.h>

//# include "../miniLibX/mlx.h"

# define	WIDTH_SCREEN	1920
# define	HEIGHT_SCREEN	1080
# define	LINE			HEIGHT_SCREEN/20

# define	BLACK		create_trgb(0, 0, 0, 0)
# define	GREEN		create_trgb(0, 0, 90, 40)
# define	GREEN_LIGHT	create_trgb(0, 0, 185, 90)
# define	RED			0xCF2500
typedef struct	s_coordonnees {
	int	x_pt;
	int	y_pt;
	int	full;
}				t_coord;

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		begin;
	t_coord *(*tab_coord);
}				t_data;


/*
FT_AFFICHAGE_C ------------------------------------------------------------------
*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_lign_horizontal(t_data vars, int x, int x_end, int y, int color);
void	ft_lign_vertical(t_data img, int x, int y, int y_end, int color);
void	ft_full(t_data vars, t_coord point);
void	ft_empty(t_data vars, t_coord point);
void	ft_grille(t_data vars);
/*
FT_GAME_LIFE_C ------------------------------------------------------------------
*/

int		ft_close(int keycode, t_data *vars);
int		key_hook(int keycode, t_data *vars);
int		render_next_frame(t_data	*vars);
t_coord	**ft_init_point(t_coord *(*tab_coord));
/*
FT_COLOR_C ----------------------------------------------------------------------
*/
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
/*
FT_RULES_C ----------------------------------------------------------------------
*/
int		ft_check_neighbor(t_coord *(*tab_coord), int nb);
void	ft_rules(t_coord *(*tab_coord));
#endif
