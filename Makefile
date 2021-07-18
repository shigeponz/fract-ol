# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 07:24:46 by hshigemu          #+#    #+#              #
#    Updated: 2021/07/17 22:05:46 by hshigemu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fractol
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g -fsanitize=address
RM			:= rm -f

UNAME		:= $(shell uname)

ifeq ($(UNAME), Linux)
LIBS 	:= -lXext -lX11
SOURCE	:= main.c error.c init.c utils.c calculate.c
else
LIBS 	:= libmlx.dylib -framework OpenGL -framework AppKit
SOURCE	:= main.c error.c init.c utils.c calculate.c
endif

LIBFTDIR		:= ./libft
MLXDIR			:= ./mlx
LINUX_MLX_DIR	:= ./minilibx-linux
DIR				:= ./srcs

LIBFT			:= ./libft/libft.a

SRCS	:= $(addprefix $(DIR)/,$(SOURCE))
OBJS	:= $(addprefix $(DIR)/,$(SOURCE:%.c=%.o))

ifeq ($(UNAME), Linux)
$(NAME): $(OBJS) $(SRCS)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(LINUX_MLX_DIR)
	cp minilibx-linux/libmlx_Linux.a .
	$(CC) $(CFLAGS) $(SRCS) -L. -L.minilibx-linux -lmlx_Linux $(LIBS) -lm $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(LINUX_MLX_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) libmlx_Linux.a

re: fclean all

.PHONY: all clean fclean re

else

$(NAME): $(OBJS) $(SRCS)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(MLXDIR)
	cp mlx/libmlx.dylib .
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
