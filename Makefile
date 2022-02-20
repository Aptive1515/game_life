# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aptive <aptive@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/22 23:12:10 by pbondoer          #+#    #+#              #
#    Updated: 2022/02/20 16:54:13 by aptive           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= game_life
OS		= $(shell uname)

# directories
SRCDIR	= ./src
INCDIR	= ./includes
OBJDIR	= ./obj

# src / obj files
SRC		= 	game_life.c \
			ft_color.c \
			ft_affichage.c \
			ft_rules.c \
			ft_hook.c \
			ft_base.c \
			ft_mouse.c

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

# mlx library
ifeq ($(OS), Linux)
	MLX		= ./miniLibX_X11/
	MLX_LNK	= -L $(MLX) -l mlx -lXext -lX11
else
	MLX		= ./miniLibX/
	MLX_LNK	= -Lmlx -lmlx -framework OpenGL -framework AppKit
endif

MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX),mlx.a)

FRAME		= -Lmlx -lmlx -framework OpenGL -framework AppKit

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft -l pthread

all: obj $(FT_LIB)  $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all
