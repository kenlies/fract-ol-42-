/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/04/19 09:44:42 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH 760
# define WIN_HEIGHT 760
# define ITERATIONS 100

# define ESC 53
# define Q 12
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126
# define SCROLL_DOWN 5
# define SCROLL_UP 4
# define PSYCHO 49
# define RESET 15
# define AUTOZOOM 6
# define W 13
# define A 0
# define S 1
# define D 2

# include "libft/libft.h"
# include "mlx.h"
# include <math.h>

typedef struct s_color
{
	int				color_count;
	int				color_range;
	int				index;
	int				color_1;
	int				color_2;
	double			ratio;
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct s_complex
{
	double		real;
	double		imag;
}					t_complex;

typedef struct s_info
{
	void			*win;
	void			*mlx;
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				iterations;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			set;
	double			x_pos;
	double			y_pos;
	double			x_mv_buf;
	double			y_mv_buf;
	double			zoom;
	double			zoom_buf;
	t_complex		c;
	t_complex		z;
	t_complex		temp_z;
	t_complex		o_mouse;
	t_complex		n_mouse;
	t_complex		d_mouse;
	unsigned char	wildcard;
	int				psycho_mode_activation;
	int				autozoom;
}					t_info;
// After testing I found that I got better performance with doubles instead
// of long doubles, but floats performed worse than doubles for some reason.
// - Didn't notice much difference in precision in those tests. 

void				init_fractal(t_info *info, void *mlx, void *win);
int					v_f(char *str);

int					check_use(int ac, char **av, t_info *info);
void				my_mlx_pixel_put(t_info *info, int x, int y, int color);

void				hooks(t_info *info, void *mlx, void *win);
int					keyhook(int keycode, t_info *info);
int					mousehook(int button, int x, int y, t_info *info);
int					loophook(t_info *info);

void				mandelbrot(t_info *info);
void				julia(t_info *info);
int					iterate(t_info *info);
int					findcolor(t_info *info, int iter);

int					exits(t_info *info);
void				psycho_function(t_info *info);
void				smoothmove(t_info *info);
void				reset(t_info *info);

#endif