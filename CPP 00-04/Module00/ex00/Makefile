# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 00:12:41 by jaromero          #+#    #+#              #
#    Updated: 2023/06/14 23:23:23 by jaromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= megaphone

SOURCES		=	megaphone.cpp

OBJECTS		=	$(SOURCES:.cpp=.o)

CC			= clang++

CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

all:		$(NAME)

$(NAME):	$(OBJECTS)
			@echo "\n	      ##### Compilando CPP Module 00 ex00 #####\n";
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