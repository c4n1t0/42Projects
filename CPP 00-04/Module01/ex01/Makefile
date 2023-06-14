# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 23:59:25 by jaromero          #+#    #+#              #
#    Updated: 2023/06/14 23:22:24 by jaromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= zombieHorde

SOURCES		=	main.cpp Zombie.cpp zombieHorde.cpp

OBJECTS		=	$(SOURCES:.cpp=.o)

CC			= clang++

CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

all:		$(NAME)

$(NAME):	$(OBJECTS)
			@echo "\n	      ##### Compilando CPP Module 01 ex01 #####\n";
			$(CC) $(CPPFLAGS) $(OBJECTS) -o $(NAME)

clean:
			@rm -rf $(OBJECTS)
			@echo "\n	       ##### Objects Cleaned!! #####\n";

fclean:	
			@rm -rf $(NAME) $(OBJECTS)
			clear
			@echo "\n	      ##### All files cleaned!! #####\n";
			

re:			fclean all
			
.PHONY:		all bonus clean fclean re