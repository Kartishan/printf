/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_part2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:32:24 by pwildcat          #+#    #+#             */
/*   Updated: 2021/12/08 14:32:25 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_lowperevod(unsigned int ch)
{
	char	*str;
	int		i;
	int		j;

	i = ft_chforsix(ch);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (0);
	j = i;
	str = strret(str, ch, i);
	write(1, str, j);
	free (str);
	return (j);
}

int	ft_perevod(unsigned int ch)
{
	char	*str;
	int		i;
	int		j;

	i = ft_chforsix(ch);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (0);
	j = i;
	i--;
	while (1)
	{
		if (ch % 16 >= 10)
			str[i] = ((ch % 16) - 10) + 'A';
		else
			str[i] = (ch % 16) + '0';
		ch = ch / 16;
		i--;
		if (ch == 0)
			break ;
	}
	str[j] = '\0';
	write(1, str, j);
	free (str);
	return (j);
}

long int	negcheckint(long int n)
{
	long int	nan;

	nan = n;
	if (nan < 0)
	{
		nan = nan * -1;
		write(1, "-", 1);
		return (nan);
	}
	return (nan);
}

long int	nbret(long int t)
{
	long int	nb;

	nb = 1;
	while (t > 9)
	{
		nb *= 10;
		t /= 10;
	}
	return (nb);
}

int	ft_printnbr(int n)
{
	long int	t;
	long int	nb;
	char		c;
	int			i;
	long int	nan;

	nan = negcheckint(n);
	i = 0;
	if (n < 0)
		i++;
	t = nan;
	nb = nbret(t);
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
