/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_part3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:51:00 by pwildcat          #+#    #+#             */
/*   Updated: 2021/12/08 14:51:01 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

unsigned long long int	checknegativeunsignded(unsigned int n)
{
	unsigned long long int	nan;

	nan = n;
	if (nan < 0)
		nan = 4294967295 - nan;
	return (nan);
}

int	ft_unsignedprintnbr(unsigned int n)
{
	unsigned long long int	t;
	unsigned long long int	nb;
	char					c;
	int						i;
	unsigned long long int	nan;

	nan = checknegativeunsignded(n);
	t = nan;
	nb = 1;
	i = 0;
	while (t > 9)
	{	
		nb *= 10;
		t /= 10;
	}
	while (nb != 0)
	{
		t = nan / nb % 10;
		c = t + '0';
		write(1, &c, 1);
		nb /= 10;
		i++;
	}
	return (i);
}

unsigned int	ft_chforlsix(unsigned long long int ch)
{
	unsigned int	i;

	i = 0;
	while (1)
	{
		ch = ch / 16;
		i++;
		if (ch == 0)
			return (i);
	}
	return (i);
}

int	ft_pp(unsigned long long int ch)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = ft_chforlsix(ch);
	j = i;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (0);
	str = strret(str, ch, i);
	write (1, "0x", 2);
	write (1, str, j);
	free (str);
	return (j + 2);
}
