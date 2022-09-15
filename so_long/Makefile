# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 00:29:09 by jaromero          #+#    #+#              #
#    Updated: 2022/09/14 10:35:37 by jaromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= srcs/so_long.a

BNAME	= bonus/so_long_bonus.a

SOURCES	=	srcs/so_long.c srcs/read_maps.c srcs/source_maps_0.c srcs/source_maps_1.c \
			srcs/limits_wall.c srcs/init_elements_0.c srcs/init_elements_1.c srcs/start_game.c \
			srcs/so_long_utils_0.c srcs/limits_collect.c srcs/player_position.c srcs/limits_exit.c \
			srcs/init_elements_2.c srcs/end_game.c srcs/key_hooks.c

BSOURCES =	bonus/so_long_bonus.c bonus/read_maps_bonus.c bonus/source_maps_0_bonus.c \
			bonus/source_maps_1_bonus.c bonus/limits_wall_bonus.c bonus/init_elements_0_bonus.c \
			bonus/init_elements_1_bonus.c bonus/start_game_bonus.c bonus/so_long_utils_0_bonus.c \
			bonus/limits_collect_bonus.c bonus/player_position_bonus.c bonus/limits_exit_bonus.c \
			bonus/init_elements_2_bonus.c bonus/end_game_bonus.c bonus/key_hooks_bonus.c \
			bonus/init_elements_3_bonus.c bonus/enemy_hooks_bonus.c bonus/limits_wall_enemy_bonus.c \
			bonus/limits_enemy_bonus.c bonus/animated_sprite_bonus.c

OBJECTS	= $(SOURCES:.c=.o)

BOBJECTS	= $(BSOURCES:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

INCLUDES	= -I include -I MLX42/include/MLX42

LIBS		= MLX42/libmlx42.a -lglfw -L /Users/${USER}/.brew/opt/glfw/lib/

all:	$(NAME)

$(NAME):	$(OBJECTS)
			@echo "\n	    ##### Comprobando NORMINETTE 42 #####\n";
			@norminette srcs/
			@echo "\n		##### Compilando Minilibx #####\n";
			@make -C MLX42/ --silent
			@cp MLX42/libmlx42.a srcs/	
			@echo "\n		##### Compilando LIBFT #####\n";
			@make -C libft/ --silent
			@cp libft/libft.a srcs/
			@echo "\n	      ##### Compilando so_long #####\n";
			@ar rcs $(NAME) $(OBJECTS)
			$(CC) $(CFLAGS) $(NAME) $(LIBS) $(INCLUDES) srcs/libft.a -o so_long

%.o: srcs/%.c
			$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

bonus:		$(BOBJECTS)
			@echo "\n	    ##### Comprobando NORMINETTE 42 #####\n";
			@norminette bonus/
			@echo "\n		##### Compilando Minilibx #####\n";
			@make -C MLX42/ --silent
			@cp MLX42/libmlx42.a srcs/	
			@echo "\n		##### Compilando LIBFT #####\n";
			@make -C libft/ --silent
			@cp libft/libft.a bonus/
			@echo "\n	      ##### Compilando so_long #####\n";
			@ar rcs $(BNAME) $(BOBJECTS)
			$(CC) $(CFLAGS) $(BNAME) $(LIBS) $(INCLUDES) bonus/libft.a -o so_long_bonus

%.o: bonus/%.c
			$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)


clean:
			@rm -rf $(OBJECTS) $(BOBJECTS)
			@make clean -C libft/ --silent
			@make clean -C MLX42/ --silent
			@echo "\n	       ##### Objects Cleaned!! #####\n";

fclean:	
			@rm -rf $(NAME) $(BNAME) srcs/libft.a srcs/libmlx42.a so_long
			@rm -rf bonus/libft.a bonus/libmlx42.a so_long_bonus
			@make fclean -C libft/ --silent
			@make clean -C MLX42/ --silent
			@rm -rf $(OBJECTS) $(BOBJECTS)
			clear
			@echo "\n	      ##### All files cleaned!! #####\n";
			

re:			fclean all
			
.PHONY:		all bonus clean fclean re