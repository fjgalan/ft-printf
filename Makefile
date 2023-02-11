# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgalan-n <fgalan-n@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 11:30:40 by fgalan-n          #+#    #+#              #
#    Updated: 2022/11/02 11:30:46 by fgalan-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_numalpha.c ft_hexadem.c
				
OBJS =	$(SRCS:.c=.o) 

CC = gcc

CFLAGS = -Wall -Werror -Wextra

.c.o:
	$(CC) -c $(CFLAGS) $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS) 
	@ar rc $(NAME) $(OBJS) 

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
