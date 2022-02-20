/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_life.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:17:29 by aptive            #+#    #+#             */
/*   Updated: 2022/02/20 17:21:53 by aptive           ###   ########.fr       */
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
# include "../miniLibX_X11/mlx.h"

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
	int	full_next;
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
void	ft_full_next(t_coord *(*tab_coord));

/*
FT_HOOK_C -----------------------------------------------------------------------
*/
int		ft_clean(t_data *vars);
int		ft_close(int keycode, t_data *vars);
int		key_hook(int keycode, t_data *vars);
/*
FT_BASE_C -----------------------------------------------------------------------
*/
void	ft_put_full(t_data *vars);
void	ft_one(t_data *vars);
void	ft_two(t_data *vars);
void	ft_three(t_data *vars);
void	ft_four(t_data *vars);
/*
FT_MOUSE_C ----------------------------------------------------------------------
*/
int		ft_mouse_hook(int keycode, int x, int y, t_data *vars);
int		ft_put_cell(int nb, t_data *vars);
int		ft_delete_cell(int nb, t_data *vars);
int		ft_find_coord(int x, int y, t_coord *(*tab_coord));
#endif
