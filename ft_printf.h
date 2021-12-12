/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:51:19 by pwildcat          #+#    #+#             */
/*   Updated: 2021/12/08 13:51:20 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int						ft_printf(const char *format, ...);
int						checked(va_list args, char c);
int						ft_putchar(int c);
int						ft_precent(void);
int						ft_putstr(const char *str);
int						ft_chforsix(unsigned int ch);
int						ft_lowperevod(unsigned int ch);
int						ft_perevod(unsigned int ch);
int						ft_pp(unsigned long long int ch);
long int				negcheckint(long int n);
int						ft_printnbr(int n);
unsigned long long int	checknegativeunsignded(unsigned int n);
int						ft_unsignedprintnbr(unsigned int n);
unsigned int			ft_chforlsix(unsigned long long int ch);
char					*strret(char *str, unsigned long long int ch,
							unsigned int i);

#endif
