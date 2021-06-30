# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 07:24:46 by hshigemu          #+#    #+#              #
#    Updated: 2021/07/01 08:10:57 by hshigemu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fractol
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -f

UNAME		:= $(shell uname)

ifeq ($(UNAME), Linux)
LIBS	:= -lmlx -lXext -lX11
SOURCE	:= fractol.c
MLX		:= ./linux_mlx/minilibx-linux
else
LIBS	:= -framework OpenGL -framework AppKit
SOURCE	:= fractol.c
MLX		:= ./mlx/libmlx.dylib
endif

LIBFTDIR		:= ./libft
MLXDIR			:= ./mlx
LINUX_MLX_DIR	:= ./linux_mlx
DIR				:= ./srcs

LIBFT			:= ./libft/libft.a

SRCS	:= $(addprefix $(DIR)/,$(SOURCE))
OBJS	:= $(addprefix $(DIR)/,$(SOURCE:%.c=%.o))

ifeq ($(UNAME), Linux)
$(NAME): $(OBJS) $(SRCS)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(LINUX_MLX_DIR)
	cp linux_mlx/libmlx_Linux.a .
	$(CC) $(CFLAGS) $(SRCS) $(MLX) $(LIBS) $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(LINUX_MLX_DIR) fclean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(MLX)

re: fclean all

.PHONY: all clean fclean re

else

$(NAME): $(OBJS) $(SRCS)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(MLXDIR)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLX) $(LIBS) -o $(NAME) -D MAC

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(MLXDIR) clean
	$(RM) $(OBJS)
	$(RM) $(MLX)

fclean: clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re

endif
