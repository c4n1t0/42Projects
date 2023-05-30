# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 00:45:15 by jaromero          #+#    #+#              #
#    Updated: 2023/05/29 18:49:04 by jaromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Zombie

SOURCES		=	main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

OBJECTS		=	$(SOURCES:.cpp=.o)

CC			= clang++

CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

all:		$(NAME)

$(NAME):	$(OBJECTS)
			@echo "\n	      ##### Compilando CPP Module 01 ex00 #####\n";
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