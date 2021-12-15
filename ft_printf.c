/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:51:15 by pwildcat          #+#    #+#             */
/*   Updated: 2021/12/08 13:51:16 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "limits.h"

int	checked(va_list args, char c)
{
	int	j;

	j = 0;
	if (c == 'c')
		j += ft_putchar(va_arg(args, int));
	if (c == 's')
		j += ft_putstr(va_arg(args, char *));
	if (c == 'p')
		j += ft_pp(va_arg(args, unsigned long long int));
	if (c == 'i')
		j += ft_printnbr(va_arg(args, int));
	if (c == 'd')
		j += ft_printnbr(va_arg(args, int));
	if (c == 'u')
		j += ft_unsignedprintnbr(va_arg(args, unsigned int));
	if (c == 'x')
		j += ft_lowperevod(va_arg(args, unsigned int));
	if (c == 'X')
		j += ft_perevod(va_arg(args, unsigned int));
	if (c == '%')
		j += ft_precent();
	return (j);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	va_list	args;

	if (!format)
		return (0);
	va_start(args, format);
	i = 0;
	j = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			j = j + checked(args, format[i + 1]);
			i++;
		}
		else
			j += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (j);
}
