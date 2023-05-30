# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 17:39:41 by jaromero          #+#    #+#              #
#    Updated: 2023/05/29 18:40:55 by jaromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= FragTrap

SOURCES	=	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJECTS		=	$(SOURCES:.cpp=.o)

CC			= clang++

CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

all:		$(NAME)

$(NAME):	$(OBJECTS)
			@echo "\n	      ##### Compilando CPP Module 03 ex02 #####\n";
			$(CC) $(CPPFLAGS) $(SOURCES) -o $(NAME)

clean:
			@rm -rf $(OBJECTS)
			@echo "\n	       ##### Objects Cleaned!! #####\n";

fclean:	
			@rm -rf $(NAME) $(OBJECTS)
			clear
			@echo "\n	      ##### All files cleaned!! #####\n";
			

re:			fclean all
			
.PHONY:		all bonus clean fclean re