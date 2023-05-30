# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 18:07:56 by jaromero          #+#    #+#              #
#    Updated: 2023/05/30 17:57:51 by jaromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= phoneBooK

SOURCES	=	MainPhoneBook.cpp ClassContact.cpp ClassPhoneBook.cpp

OBJECTS		=	$(SOURCES:.cpp=.o)

CC		= clang++

CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME):	$(OBJECTS)
			@echo "\n	      ##### Compilando CPP Module 00 ex01 #####\n";
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