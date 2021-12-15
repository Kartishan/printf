/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_part1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:23:18 by pwildcat          #+#    #+#             */
/*   Updated: 2021/12/08 14:23:19 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_precent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_chforsix(unsigned int ch)
{
	unsigned int	del;
	int				i;

	i = 0;
	del = ch;
	while (del >= 0)
	{
		del = del / 16;
		i++;
		if (del == 0)
			break ;
	}
	return (i);
}

char	*strret(char *str, unsigned long long int ch, unsigned int i)
{
	unsigned int	j;

	j = i;
	i--;
	while (1)
	{
		if (ch % 16 >= 10)
			str[i] = ((ch % 16) - 10) + 'a';
		else
			str[i] = (ch % 16) + '0';
		ch = ch / 16;
		i--;
		if (ch == 0)
			break ;
	}
	str[j] = '\0';
	return (str);
}
