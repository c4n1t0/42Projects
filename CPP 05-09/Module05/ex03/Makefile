# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 01:43:09 by jaromero          #+#    #+#              #
#    Updated: 2023/06/14 23:11:33 by jaromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= InternForm

SOURCES	=	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

OBJECTS	=	$(SOURCES:.cpp=.o)

CC		= clang++

CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME):	$(OBJECTS)
			@echo "\n	      ##### Compilando CPP Module 05 ex03 #####\n";
			$(CC) $(CPPFLAGS) $(OBJECTS) -o $(NAME)

clean:
			@rm -rf $(OBJECTS) *_shrubbery
			@echo "\n	       ##### Objects Cleaned!! #####\n";

fclean:	
			@rm -rf $(NAME) $(OBJECTS) *_shrubbery
			clear
			@echo "\n	      ##### All files cleaned!! #####\n";
			

re:			fclean all
			
.PHONY:		all bonus clean fclean re