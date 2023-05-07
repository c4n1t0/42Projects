# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 10:43:53 by jaromero          #+#    #+#              #
#    Updated: 2022/12/28 01:08:05 by jaromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

# NAME_BONUS	=

SOURCES		=	srcs/main.c srcs/utils_0.c srcs/utils_1.c srcs/ft_echo_0.c \
				srcs/directory.c srcs/signals.c srcs/ft_exec_comd.c \
				srcs/exc_rest.c srcs/pipex_0.c srcs/var_env_1.c srcs/export_1.c\
				srcs/pipex_1.c srcs/export_0.c srcs/unset.c srcs/var_env_0.c \
				srcs/ft_exit.c srcs/quote_0.c srcs/redirection_prepare.c \
				srcs/utils_2.c srcs/check_pipe.c srcs/redirections_out.c \
				srcs/infile_and_outfile.c srcs/redirections_in_0.c \
				srcs/quote_1.c srcs/redirections_in_1.c srcs/wildcards.c \
				srcs/utils_3.c srcs/wildcards_utils_1.c srcs/wildcards_utils_2.c \
				srcs/wildcards_utils_3.c srcs/ft_error_exec.c srcs/analytics.c \
				srcs/redirections_in_2.c srcs/redirections_in_3.c
				
OBJECTS		= $(SOURCES:.c=.o)

CC			= gcc

#INCLUDES	= -I srcs -I /Users/${USER}/.brew/opt/readline/include

INCLUDES	= -I srcs -I /usr/local/opt/readline/include

#LIBS		= -L /Users/${USER}/.brew/opt/readline/lib -lreadline

LIBS		= -L /usr/local/opt/readline/lib -lreadline

CFLAGS		= -Wall -Wextra -Werror

all:		$(NAME)

srcs/%.o: srcs/%.c
			$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)
			
$(NAME):	$(OBJECTS)
			@echo "\n	    ##### Comprobando NORMINETTE 42 #####\n";
			@norminette	srcs/
			@echo "\n		##### Compilando LIBFT #####\n";
			@make -C libft/ --silent
			@cp libft/libft.a srcs/
			@echo "\n	      ##### Compilando minishell #####\n";
			$(CC) $(CFLAGS)  $(LIBS) srcs/libft.a $(OBJECTS) -o $(NAME)

obj:
	echo $(OBJECTS)

bonus:		fclean all		

%.o: bonus/%.c
			$(CC) -c $(CFLAGS) $?


clean:
			@rm -rf $(OBJECTS)
			@make clean -C libft/ --silent
			@echo "\n	       ##### Objects Cleaned!! #####\n";

fclean:	
			@rm -rf $(NAME) srcs/libft.a minishell
			@make fclean -C libft/ --silent
			@rm -rf $(OBJECTS)
			clear
			@echo "\n	      ##### All files cleaned!! #####\n";
			

re:			fclean all
			
.PHONY:		all bonus clean fclean re