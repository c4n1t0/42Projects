# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 17:39:41 by jaromero          #+#    #+#              #
#    Updated: 2023/05/02 17:45:13 by jaromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= FragTrap

SOURCES	=	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

CC		= clang++

CFLAGS	= -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME):
			@echo "\n	      ##### Compilando CPP Module 03 ex02 #####\n";
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