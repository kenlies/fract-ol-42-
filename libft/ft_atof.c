/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.fr>                     +#+  +:+       +#+  */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:11:43 by aotsala           #+#    #+#             */
/*   Updated: 2022/10/25 15:11:48 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof_extention(const char *str, int i)
{
	double	decimal_place;
	double	dec_res;

	decimal_place = 1;
	dec_res = 0;
	while (ft_isdigit(str[i]))
	{
		decimal_place *= 10;
		dec_res += (str[i] - '0') / decimal_place;
		i++;
	}
	return (dec_res);
}

double	ft_atof(const char *str)
{
	int		i;
	double	int_res;
	double	dec_res;
	double	n;

	i = 0;
	int_res = 0;
	dec_res = 0;
	n = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		int_res = int_res * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.' && str[i++])
		dec_res = ft_atof_extention(str, i);
	return (n * (int_res + dec_res));
}
