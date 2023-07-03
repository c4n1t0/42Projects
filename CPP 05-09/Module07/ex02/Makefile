# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 20:10:48 by jaromero          #+#    #+#              #
#    Updated: 2023/06/29 21:20:45 by jaromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Array

SOURCES	=	main.cpp

OBJECTS	=	$(SOURCES:.cpp=.o)

CC		= clang++

CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME):	$(OBJECTS)
			@echo "\n	      ##### Compilando CPP Module 07 ex02 #####\n";
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