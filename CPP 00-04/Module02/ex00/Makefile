# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 00:50:52 by jaromero          #+#    #+#              #
#    Updated: 2023/03/13 09:34:40 by jaromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= a.out

SOURCES	=	main.cpp Fixed.cpp

CC		= clang++

CFLAGS	= -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME):
			@echo "\n	      ##### Compilando CPP Module 02 ex00 #####\n";
			$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
			@rm -rf $(NAME)
			@echo "\n	       ##### Objects Cleaned!! #####\n";

fclean:	
			@rm -rf $(NAME)
			clear
			@echo "\n	      ##### All files cleaned!! #####\n";
			

re:			fclean all
			
.PHONY:		all bonus clean fclean re