# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 07:24:46 by hshigemu          #+#    #+#              #
#    Updated: 2021/07/11 23:50:01 by hshigemu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fractol
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -f

UNAME		:= $(shell uname)

ifeq ($(UNAME), Linux)
LIBS 	:= -lXext -lX11
SOURCE	:= main.c error.c init.c utils.c
MLX		:= ./linux_mlx/minilibx-linux
else
LIBS 	:= libmlx.dylib -framework OpenGL -framework AppKit
SOURCE	:= main.c error.c init.c utils.c
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
	cp $(MLX) .
	$(CC) $(CFLAGS) $(SRCS) -L. -L.minilibx-linux -lmlx_Linux $(LIBS) -lm $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(LINUX_MLX_DIR) fclean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) minilibx-linux

re: fclean all

.PHONY: all clean fclean re

else

$(NAME): $(OBJS) $(SRCS)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(MLXDIR)
	cp $(MLX) .
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) libmlx.dylib -o $(NAME) -D MAC

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(MLXDIR) clean
	$(RM) $(OBJS)
	$(RM) $(MLX)

fclean: clean
	$(RM) $(NAME) libmlx.dylib

re:		fclean all

.PHONY: all clean fclean re

endif
