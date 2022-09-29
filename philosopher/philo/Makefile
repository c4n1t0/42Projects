# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 00:28:46 by jaromero          #+#    #+#              #
#    Updated: 2022/09/22 22:54:52 by jaromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo.a

SOURCES	=	philo_main.c philo_utils_0.c philo_save_init.c philo_cicle.c \
			philo_pthread.c

OBJECTS	= $(SOURCES:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJECTS)
			@echo "\n	    ##### Comprobando NORMINETTE 42 #####\n";
			@norminette .
			@echo "\n	     ##### Compilando PhilosoPher! #####\n";
			@ar rcs $(NAME) $(OBJECTS)
			$(CC) $(CFLAGS) $(NAME) -o philo

%.o: %.c
			$(CC) $(CFLAGS) -o $@ -c $<

clean:
			@rm -rf $(OBJECTS)
			@echo "\n	       ##### Objects Cleaned!! #####\n";

fclean:	
			@rm -rf $(NAME) philo
			@rm -rf $(OBJECTS)
			clear
			@echo "\n	      ##### All files cleaned!! #####\n";

re:			fclean all
			
.PHONY:		all bonus clean fclean re