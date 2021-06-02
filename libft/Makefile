#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelamran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/07 15:38:40 by aelamran          #+#    #+#              #
#    Updated: 2018/10/11 16:34:26 by aelamran         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -c *.c
	ar rc $(NAME) *.o

clean :
	/bin/rm -f *.o

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all