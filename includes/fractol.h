/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 07:03:22 by hshigemu          #+#    #+#             */
/*   Updated: 2021/07/27 23:20:02 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>

# define INVALID_COMMANDLINE_NUM_ERR "invalid number of command line\n"
# define HELP_MESSAGE1 "-------HELP-------\n\n"
# define HELP_MESSAGE2 "[Julia]\n\n./fractol J (param_x) (param_y)\n"
# define HELP_MESSAGE3 "** param_x and param_y must be REAL NUMBER\n\n"
# define HELP_MESSAGE4 "[Mandelbrot]\n\n./fractol M\n\n"
/*
# define HELP_MESSAGE5 "[Bonus]\n\n./fractol M2 (param)\n\n"
*/
# define HELP_MESSAGE6 "------------------\n"
# define MEMALLOC_ERR "memory allocation error!!\n"
# define MANDELBROT_ID 0
# define JULIA_ID 1
# define MANDELBROT_BONUS_ID 2
# define WIN_HEIGHT 800
# define WIN_WIDTH 800
# define SQUARE_RANGE 4
# define PARTICLE_SIZE 50

# ifdef MAC

#  define X_EVENT_KEY_PRESS 2
#  define X_EVENT_KEY_EXIT 17
#  define K_ESC 53
#  define SCROLL_UP 4
#  define SCROLL_DOWN 5
#  define KEY_1 18
#  define KEY_2 19
#  define KEY_3 20
#  define KEY_4 21
#  define KEY_5 23
#  define KEY_6 22
#  define KEY_7 26
#  define KEY_8 28
#  define KEY_9 25
#  define KEY_0 29

# else

#  define X_EVENT_KEY_PRESS 2
#  define X_EVENT_KEY_EXIT 33
#  define K_ESC 65307
#  define SCROLL_UP 4
#  define SCROLL_DOWN 5
#  define KEY_0 48
#  define KEY_1 49
#  define KEY_2 50
#  define KEY_3 51
#  define KEY_4 52
#  define KEY_5 53
#  define KEY_6 54
#  define KEY_7 55
#  define KEY_8 56
#  define KEY_9 57

# endif

typedef struct s_vars
{
	void		*mlx;
	void		*win;
}	t_vars;

typedef struct s_image
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_env
{
	double			param1;
	double			param2;
	double			org_x;
	double			org_y;
	int				pos_x;
	int				pos_y;
	int				frac_id;
	int				buf[WIN_HEIGHT][WIN_WIDTH];
	unsigned int	color;
	double			zoom;
	t_vars			var;
	t_image			img;
}	t_env;

void		ft_print_error(char *message);
void		ft_print_help(void);
int			ft_validate_argv(int argc, char *argv[]);
int			ft_validate_float(char *obj);
void		ft_mandelbrot(void);
int			ft_close(t_env *frac);
t_env		ft_env_init(int argc, char *argv[]);
int			ft_keypress(int key, t_env *frac);
void		ft_put_image(t_env *e);
int			ft_mouse_move(int key, int x, int y, t_env *frac);
void		ft_put_color(t_env *e);
int			ft_calculate(t_env *e, int x, int y);

#endif