/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 07:03:22 by hshigemu          #+#    #+#             */
/*   Updated: 2021/07/11 23:54:03 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>

# define INVALID_COMMANDLINE_NUM_ERR "invalid number of command line\n"
# define HELP_MESSAGE "-------HELP-------\n"
# define COMMAND_EXAMPLE1 "./fractol julia (parameters)\n"
# define COMMAND_EXAMPLE2 "./fractol mandelbrot\n"
# define MEMALLOC_ERR "memory allocation error!!\n"
# define MANDELBROT_ID 0
# define JULIA_ID 1
# define WIN_HEIGHT 500
# define WIN_WIDTH 809
# define X_EVENT_KEY_EXIT 33

# define SCROLL_UP 4
# define SCROLL_DOWN 5

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

typedef struct s_fractol
{
	int		julia_x;
	int		julia_y;
	int		frac_id;
	float	zoom;
	t_vars	var;
	t_image	img;
}	t_fractol;

void		ft_print_error(char *message);
void		ft_print_help(void);
int			ft_validate_argv(char *argv[]);
void		ft_mandelbrot(void);
int			ft_close(t_fractol *frac);
t_fractol	ft_frac_init(int argc, char *argv[]);

#endif