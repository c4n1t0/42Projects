# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 00:28:46 by jaromero          #+#    #+#              #
#    Updated: 2022/09/29 12:53:05 by jaromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo_bonus.a

SOURCES	=	philo_main_bonus.c philo_utils_0_bonus.c philo_save_init_bonus.c \
			philo_pthread_bonus.c philo_cicle_bonus.c

OBJECTS	= $(SOURCES:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJECTS)
			@echo "\n	    ##### Comprobando NORMINETTE 42 #####\n";
			@NORMINETTE .
			@echo "\n	     ##### Compilando PhilosoPher! #####\n";
			@ar rcs $(NAME) $(OBJECTS)
			$(CC) $(CFLAGS) $(NAME) -o philo_bonus

%.o: %.c
			$(CC) $(CFLAGS) -o $@ -c $<

clean:
			@rm -rf $(OBJECTS)
			@echo "\n	       ##### Objects Cleaned!! #####\n";

fclean:	
			@rm -rf $(NAME) philo_bonus
			@rm -rf $(OBJECTS)
			clear
			@echo "\n	      ##### All files cleaned!! #####\n";

re:			fclean all
			
.PHONY:		all bonus clean fclean re