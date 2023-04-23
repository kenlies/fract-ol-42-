/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/04/19 07:07:46 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exits(t_info *info)
{
	(void)info;
	exit(0);
}

void	my_mlx_pixel_put(t_info *info, int x, int y, int color)
{
	char	*dst;

	dst = info->addr
		+ (y * info->line_length + x * (info->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_fractal(t_info *info, void *mlx, void *win)
{
	info->mlx = mlx;
	info->win = win;
	info->width = WIN_WIDTH;
	info->height = WIN_HEIGHT;
	info->iterations = ITERATIONS;
	info->zoom = 0.3;
	info->wildcard = 252;
}

void	reset(t_info *info)
{
	if (info->set == 'm' || info->set == 'b')
	{
		info->zoom = 0.3;
		info->x_pos = -0.5;
		info->y_pos = 0;
	}
	else
	{
		info->zoom = 0.3;
		info->x_pos = 0;
		info->y_pos = 0;
	}
}
