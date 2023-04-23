/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/04/17 06:15:34 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_info *info)
{
	int	color;
	int	iterations;
	int	i;

	i = 0;
	while (i < info->width * info->height)
	{
		info->c.real = (i % info->width - info->width / 2)
			/ (info->width * info->zoom) + info->x_pos;
		info->c.imag = (i / info->width - info->height / 2) / (info->height
				* info->zoom) + info->y_pos;
		info->z.real = 0;
		info->z.imag = 0;
		iterations = iterate(info);
		color = findcolor(info, iterations);
		my_mlx_pixel_put(info, i % info->width, i / info->width, color);
		i++;
	}
}

void	julia(t_info *info)
{
	int	color;
	int	iterations;
	int	i;

	i = 0;
	while (i < info->width * info->height)
	{
		info->z.real = (i % info->width - info->width / 2)
			/ (info->zoom * info->width) + info->x_pos;
		info->z.imag = (i / info->width - info->height / 2) / (info->zoom
				* info->height) + info->y_pos;
		iterations = iterate(info);
		color = findcolor(info, iterations);
		my_mlx_pixel_put(info, i % info->width, i / info->width, color);
		++i;
	}
}

int	iterate(t_info *info)
{
	int	iter;

	iter = 0;
	while (iter++ < info->iterations)
	{
		info->temp_z.real = pow(info->z.real, 2) - pow(info->z.imag, 2);
		if (info->set == 'b')
			info->temp_z.imag = fabs(2 * info->z.real * info->z.imag);
		else
			info->temp_z.imag = 2 * info->z.real * info->z.imag;
		info->z.real = info->temp_z.real + info->c.real;
		info->z.imag = info->temp_z.imag + info->c.imag;
		if (fabs(info->z.real + info->z.imag) > 4)
			break ;
	}
	return (iter);
}
// for burning ship we only need to set absolute values for imaginary part,
// since any negative value squared is positive.
// also I didn't need to bother with an extra function for burningship,
// because it is so similiar to mandelbrot.

void	normalize(t_info *info, t_color *clr)
{
	clr->r = (clr->r % info->wildcard) * info->wildcard;
	clr->g = (clr->g % info->wildcard) * info->wildcard;
	clr->b = (clr->b % info->wildcard) * info->wildcard;
}

int	findcolor(t_info *info, int iter)
{
	t_color		clr;
	const int	palette[] = {0xffffff, 0xe6f9ff, 0xccf2ff, 0xb3ecff, 0x99e6ff,
		0x80dfff, 0x66d9ff, 0x4dd2ff, 0x33ccff, 0x1ac6ff, 0x00bfff, 0x00ace6,
		0x0099cc, 0x0086b3, 0x007399, 0x006080, 0x004d66, 0x00394d, 0x002633,
		0x00131a, 0x1a000, 0x330000, 0x4d0000, 0x660000, 0x800000, 0x990000,
		0xb30000, 0xcc0000, 0xe60000, 0xff0000, 0xe60000, 0xcc0000, 0xb30000,
		0x990000, 0x800000, 0x660000, 0x4d0000, 0x330000, 0x1a0000, 0x000000};

	if (iter >= info->iterations)
		return (0x000000);
	clr.color_count = 40;
	clr.color_range = info->iterations / clr.color_count;
	clr.index = iter / clr.color_range;
	clr.color_1 = palette[clr.index];
	clr.color_2 = palette[clr.index + 1];
	clr.ratio = (double)(iter % clr.color_range) / clr.color_range;
	clr.r = (1 - clr.ratio) * ((clr.color_1 >> 16) & 0xFF) + clr.ratio
		* ((clr.color_2 >> 16) & 0xFF);
	clr.g = (1 - clr.ratio) * ((clr.color_1 >> 8) & 0xFF) + clr.ratio
		* ((clr.color_2 >> 8) & 0xFF);
	clr.b = (1 - clr.ratio) * (clr.color_1 & 0xFF) + clr.ratio
		* (clr.color_2 & 0xFF);
	if (info->psycho_mode_activation == 1)
		normalize(info, &clr);
	return ((clr.r << 16) | (clr.g << 8) | clr.b);
}
// range = determines the number of iterations for each color in the palette
// for example: count=12 iterations=120, then range=10, because
// each color will be used for 10 iterations
/**/
// ratio = ratio of the current iteration count within the current color range.
// for example: iter=56 range=10, then ratio=0.6 because the current iteration
// is 6/10 of the way between the current color and next color in the palette.
