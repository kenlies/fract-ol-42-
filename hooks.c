/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/04/22 12:43:25 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hooks(t_info *info, void *mlx, void *win)
{
	mlx_key_hook(win, keyhook, info);
	mlx_mouse_hook(win, mousehook, info);
	mlx_loop_hook(mlx, loophook, info);
	mlx_hook(win, 17, 0, exits, info);
}

int	loophook(t_info *info)
{
	if (!info->img)
		info->img = mlx_new_image(info->mlx, info->width, info->height);
	if (!info->addr)
	{
		info->addr = mlx_get_data_addr(info->img, &info->bits_per_pixel,
				&info->line_length, &info->endian);
	}
	if (info->psycho_mode_activation)
		psycho_function(info);
	if (info->autozoom)
		info->zoom *= 1.02;
	if (info->set == 'm' || info->set == 'b')
		mandelbrot(info);
	else if (info->set == 'j')
		julia(info);
	smoothmove(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	return (0);
}

void	smoothmove(t_info *info)
{
	info->x_pos += info->x_mv_buf / 8;
	info->x_mv_buf -= info->x_mv_buf / 8;
	info->y_pos += info->y_mv_buf / 8;
	info->y_mv_buf -= info->y_mv_buf / 8;
	info->x_pos -= info->d_mouse.real / 8;
	info->d_mouse.real -= info->d_mouse.real / 8;
	info->y_pos -= info->d_mouse.imag / 8;
	info->d_mouse.imag -= info->d_mouse.imag / 8;
}

int	keyhook(int keycode, t_info *info)
{
	double	step;

	step = 0.04 / info->zoom;
	if (keycode == ESC || keycode == Q)
		exit(0);
	if (keycode == RESET)
		reset(info);
	else if (keycode == LEFT_ARROW || keycode == A)
		info->x_mv_buf -= step;
	else if (keycode == RIGHT_ARROW || keycode == D)
		info->x_mv_buf += step;
	else if (keycode == UP_ARROW || keycode == W)
		info->y_mv_buf -= step;
	else if (keycode == DOWN_ARROW || keycode == S)
		info->y_mv_buf += step;
	else if (keycode == PSYCHO && info->psycho_mode_activation == 0)
		info->psycho_mode_activation = 1;
	else if (keycode == PSYCHO && info->psycho_mode_activation == 1)
		info->psycho_mode_activation = 0;
	else if (keycode == AUTOZOOM && info->autozoom == 0)
		info->autozoom = 1;
	else if (keycode == AUTOZOOM && info->autozoom == 1)
		info->autozoom = 0;
	return (0);
}

int	mousehook(int button, int x, int y, t_info *info)
{
	double	z_old;
	double	z_new;

	z_old = info->zoom;
	z_new = 0;
	if (button == SCROLL_UP || button == 1)
		z_new = info->zoom * 1.08;
	else if (button == SCROLL_DOWN || button == 2)
		z_new = info->zoom / 1.19;
	else
		return (0);
	info->o_mouse.real = (x - info->width / 2)
		/ (info->width * z_old) + info->x_pos;
	info->o_mouse.imag = (y - info->height / 2)
		/ (info->height * z_old) + info->y_pos;
	info->zoom = z_new;
	info->n_mouse.real = (x - info->width / 2)
		/ (info->width * z_new) + info->x_pos;
	info->n_mouse.imag = (y - info->height / 2)
		/ (info->height * z_new) + info->y_pos;
	info->d_mouse.real = info->n_mouse.real - info->o_mouse.real;
	info->d_mouse.imag = info->n_mouse.imag - info->o_mouse.imag;
	info->x_pos -= info->d_mouse.real;
	info->y_pos -= info->d_mouse.imag;
	return (0);
}
// I have no idea why it works by substracting from x/y_pos rather
// than adding, I think it might have something to do with mlx
// and how the pixels are drawn...