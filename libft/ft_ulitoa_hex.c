/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulitoa_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:10:34 by aotsala           #+#    #+#             */
/*   Updated: 2022/11/25 03:46:11 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

int	count_length(unsigned long long nb)
{
	size_t	i;

	i = 0;
	while (nb)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

char	*ft_ulitoa_hex(unsigned long long nb)
{
	char	*str;
	char	*tab;
	int		size;

	size = 0;
	tab = "0123456789abcdef";
	size = count_length(nb);
	if (nb == 0)
		size++;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[ft_abs(nb % 16)];
		size--;
		nb = nb / 16;
	}
	return (str);
}
