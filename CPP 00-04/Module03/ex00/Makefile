# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 20:54:31 by jaromero          #+#    #+#              #
#    Updated: 2023/03/15 01:30:16 by jaromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ClapTrap

SOURCES	=	main.cpp ClapTrap.cpp

CC		= clang++

CFLAGS	= -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME):
			@echo "\n	      ##### Compilando CPP Module 03 ex00 #####\n";
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