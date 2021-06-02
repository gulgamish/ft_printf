#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelamran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/27 18:03:10 by aelamran          #+#    #+#              #
#    Updated: 2019/01/17 18:05:28 by aelamran         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=libftprintf.a

SRCS=srcs/*.c

all:$(NAME)

$(NAME):
	make -C libft re
	gcc -Wall -Wextra -Werror -c $(SRCS) -I includes/
	ar rc $(NAME) *.o libft/*.o

clean:
	make -C libft clean
	/bin/rm -f *.o

fclean:clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all
