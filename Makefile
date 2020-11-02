# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/07 07:07:34 by jolim             #+#    #+#              #
#    Updated: 2020/11/01 11:51:05 by jolim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re bonus

AR = ar
ARFLAGS = rcv

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

OBJS = $(SRCS:.c=.o)

SRCS = ft_align.c \
		ft_dtoa.c \
		ft_p_char.c \
		ft_p_dec.c \
		ft_p_hex.c \
		ft_p_ptr.c \
		ft_p_str.c \
		ft_printf.c \
		ft_read_spec.c \
		ft_spec_utils.c \
		ft_utils.c \
		ft_xtoa.c \
		ft_p_unsigned.c \

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)


%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< 

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
