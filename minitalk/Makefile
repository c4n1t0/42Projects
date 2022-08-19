# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 17:21:57 by jaromero          #+#    #+#              #
#    Updated: 2022/08/11 19:21:04 by jaromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	srcs/minitalk.a

NAME_SERVER	=	server

NAME_CLIENT	=	client

SOURCES		=	srcs/server.c srcs/client.c

OBJECTS		=	$(SOURCES:.c=.o)

CC			= 	gcc

CFLAGS		=	-Wall -Wextra -Werror

all: 		$(NAME)

$(NAME):	$(OBJECTS)
			@echo "\n	 ##### Comprobando NORMINETTE 42 #####\n";
			@norminette srcs/
			@echo "\n	     ##### Compilando LIBFT #####\n";
			@make -C libft/ --silent
			@cp libft/libft.a srcs/
			@echo "\n	   ##### Compilando minitalk #####\n";
			@ar -rc $(NAME) $(OBJECTS)
			$(CC) $(CFLAGS) srcs/libft.a srcs/server.o -o $(NAME_SERVER)
			$(CC) $(CFLAGS) srcs/libft.a srcs/client.o -o $(NAME_CLIENT)

bonus:		
			make all

clean:
			@rm -rf $(OBJECTS)
			@make clean -C libft/ --silent

fclean: 	clean
			@make fclean -C libft/ --silent
			@rm -rf srcs/libft.a $(NAME) $(NAME_SERVER) $(NAME_CLIENT)
			@clear screen
			@echo "\n		   ##### All files cleaned #####\n";

re: 		fclean all

.PHONY: 	all clean re fclean