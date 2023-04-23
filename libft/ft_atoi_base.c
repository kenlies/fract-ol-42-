/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:28:19 by aotsala           #+#    #+#             */
/*   Updated: 2022/11/20 20:11:21 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_valid(char c, int base)
{
	char	*digits1;
	char	*digits2;

	digits1 = "0123456789abcdef";
	digits2 = "0123456789ABCDEF";
	while (base--)
		if (digits1[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

int	hex_to_int(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int base)
{
	int			i;
	long int	res;
	int			n;

	i = 0;
	res = 0;
	n = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (is_valid(str[i], base))
	{
		res = res * base + hex_to_int(str[i]);
		i++;
	}
	return (res * n);
}
