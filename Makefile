# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 07:24:46 by hshigemu          #+#    #+#              #
#    Updated: 2021/07/01 07:32:19 by hshigemu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fractol
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -f

UNAME		:= $(shell uname)

ifeq ($(UNAME), Linux)
LIBS		:= -lXext -lX11
else
LIBS		:= libmlx.dylib -framework OpenGL -framework AppKit
endif

LIBFTDIR	:= ./libft
MLXDIR		:= ./mlx
LINUX_MLX_DIR = ./linux_mlx
