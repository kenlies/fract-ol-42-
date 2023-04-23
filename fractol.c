/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/04/21 09:38:05 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	psycho_function(t_info *info)
{
	static int	switch1 = 1;

	if (info->wildcard <= 255 && switch1)
	{
		info->wildcard++;
		if (info->wildcard == 255)
			switch1 = 0;
		return ;
	}	
	else if (info->wildcard > 250 && !switch1)
	{
		info->wildcard--;
		if (info->wildcard == 250)
			switch1 = 1;
	}
}

void	how_to(void)
{
	ft_printf("use:\n");
	ft_printf("     ./fractol mandelbrot");
	ft_printf("\n");
	ft_printf("     ./fractol julia [float] [float]");
	ft_printf("\n");
	ft_printf("     ./fractol burningship\n");
	ft_printf("\n");
	ft_printf("*******************************************\n");
	ft_printf("*                                         *\n");
	ft_printf("* Space:       activate psycho mode 🤡🔪  *\n");
	ft_printf("* R:           reset                      *\n");
	ft_printf("* Z:           autozoom                   *\n");
	ft_printf("* Scroll:      +- zoom                    *\n");
	ft_printf("* R&L click:   +- zoom                    *\n");
	ft_printf("* Arrows:      move                       *\n");
	ft_printf("* WASD:        move                       *\n");
	ft_printf("* ESC & Q:     quit                       *\n");
	ft_printf("*                                         *\n");
	ft_printf("*******************************************\n");
	ft_printf("\n");
}

int	v_f(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '-' && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_use(int ac, char **av, t_info *info)
{
	if (ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
	{
		ft_bzero(info, sizeof(*info));
		info->x_pos = -0.5;
		info->set = 'm';
	}
	else if (ac == 4 && !ft_strcmp(av[1], "julia") && v_f(av[2]) && v_f(av[3]))
	{
		ft_bzero(info, sizeof(*info));
		info->c.real = ft_atof(av[2]);
		info->c.imag = ft_atof(av[3]);
		info->set = 'j';
	}
	else if (ac == 2 && !ft_strcmp(av[1], "burningship"))
	{
		ft_bzero(info, sizeof(*info));
		info->x_pos = -0.5;
		info->set = 'b';
	}
	else
	{
		how_to();
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "fructal");
	if (!win)
		return (1);
	if (check_use(argc, argv, &info) == 0)
		init_fractal(&info, mlx, win);
	else
	{
		mlx_destroy_window(mlx, win);
		exit(1);
	}
	hooks(&info, mlx, win);
	mlx_loop(mlx);
}
