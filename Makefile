# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 15:04:25 by pwildcat          #+#    #+#              #
#    Updated: 2021/12/08 15:04:26 by pwildcat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a

SRCS =	ft_printf.c	ft_functions_part1.c\
		ft_functions_part2.c ft_functions_part3.c
HEADER = ft_printf.h

OBJ	=	$(SRCS:%.c=%.o)


CFLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	: $(OBJ) $(HEADER)
		ar rcs $(NAME) $?
%.o : %.c
	gcc $(CFLAGS) -c $< -o $@
clean	:
	rm -f $(OBJ)
fclean	:	clean
	rm -f $(NAME)
re		:	fclean all

.PHONY	:	all clean fclean re 