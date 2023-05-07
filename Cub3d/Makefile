# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 09:30:28 by jaromero          #+#    #+#              #
#    Updated: 2023/04/24 00:29:32 by jaromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	srcs/cub3D.a

BNAME		=	bonus/cub3D_bonus.a

SOURCES		=	srcs/main.c srcs/checkMap_0.c srcs/ft_split_remake.c srcs/checkMap_4.c\
				srcs/checkMap_1.c srcs/checkMap_2.c srcs/utilsCub_0.c srcs/DDAalg_0.c \
				srcs/bresen_0.c srcs/define_params.c srcs/utilsMov.c srcs/utilsLook.c \
				srcs/checkMap_3.c srcs/DDAalg_1.c srcs/bresen_1.c srcs/init_and_delete.c

BSOURCES	=	bonus/main_bonus.c bonus/checkMap_0_bonus.c bonus/ft_split_remake_bonus.c \
				bonus/checkMap_4_bonus.c bonus/checkMap_1_bonus.c bonus/checkMap_2_bonus.c \
				bonus/utilsCub_0_bonus.c bonus/DDAalg_0_bonus.c bonus/bresen_0_bonus.c \
				bonus/define_params_bonus.c bonus/utilsMov_bonus.c bonus/utilsLook_bonus.c \
				bonus/checkMap_3_bonus.c bonus/cub_bresen_s_bonus.c bonus/sprites_bonus.c \
				bonus/bresen_1_bonus.c bonus/DDAalg_1_bonus.c bonus/init_and_delete_0_bonus.c \
				bonus/init_and_delete_1_bonus.c bonus/sprite_player_bonus.c \
				bonus/mini_map_bonus.c bonus/hook_game_0_bonus.c bonus/hook_game_1_bonus.c

OBJECTS		=	$(SOURCES:.c=.o)

BOBJECTS	=	$(BSOURCES:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

INCLUDES	=	-I include -I MLX42/include/MLX42

LIBS		=	MLX42/libmlx42.a -lglfw -L /Users/${USER}/.brew/opt/glfw/lib/

all:		$(NAME)

$(NAME):	$(OBJECTS)
			@echo "\n	    ##### Comprobando NORMINETTE 42 #####\n";
			@norminette srcs/
			@echo "\n		##### Compilando MLX42 #####\n";
			@make -C MLX42/ --silent
			@cp MLX42/libmlx42.a srcs/	
			@echo "\n		##### Compilando LIBFT #####\n";
			@make -C libft/ --silent
			@cp libft/libft.a srcs/
			@echo "\n	      ##### Compilando Cub3D #####\n";
			@ar rcs $(NAME) $(OBJECTS)
			$(CC) $(CFLAGS) $(NAME) $(LIBS) $(INCLUDES) srcs/libft.a -o cub3D

%.o: srcs/%.c
			$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

bonus:		$(BNAME)

$(BNAME):	$(BOBJECTS)
			@echo "\n	    ##### Comprobando NORMINETTE 42 #####\n";
			@norminette bonus/
			@echo "\n		##### Compilando MLX42 #####\n";
			@make -C MLX42/ --silent
			@cp MLX42/libmlx42.a bonus/	
			@echo "\n		##### Compilando LIBFT #####\n";
			@make -C libft/ --silent
			@cp libft/libft.a bonus/
			@echo "\n	      ##### Compilando Cub3D #####\n";
			@ar rcs $(BNAME) $(BOBJECTS)
			$(CC) $(CFLAGS) $(BNAME) $(LIBS) $(INCLUDES) bonus/libft.a -o cub3d_bonus

%.o: bonus/%.c
			$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

clean:
			@rm -rf $(OBJECTS) $(BOBJECTS)
			@make clean -C libft/ --silent
			@make clean -C MLX42/ --silent
			@echo "\n	       ##### Objects Cleaned!! #####\n";

fclean:	
			@rm -rf $(NAME) $(BNAME) srcs/libft.a srcs/libmlx42.a cub3D bonus/libft.a bonus/libmlx42.a cub3D_bonus
			@make fclean -C libft/ --silent
			@make clean -C MLX42/ --silent
			@rm -rf $(OBJECTS) $(BOBJECTS)
			clear
			@echo "\n	      ##### All files cleaned!! #####\n";
			

re:			fclean all
			
.PHONY:		all bonus clean fclean re