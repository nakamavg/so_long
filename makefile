# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgomez-m <dgomez-m@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 17:03:22 by dgomez-m          #+#    #+#              #
#    Updated: 2024/02/16 17:06:26 by dgomez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
MLX_CF		:= -framework OpenGL -framework AppKit
CFLAGS		:= -Wall -Wextra -Werror -Ilib/libft 
MLX_PATH	:= lib/mlx
LIBFT_PATH	:= lib/libft
FT_PRINTF_PATH	:= lib/ft_printf
INCLUDE 	:= src/so_long.h
SRC 		:= src/charge_img.c src/errors.c src/flood_fill.c src/getmap.c \
				src/keys.c src/main.c src/put_things.c src/read_map.c\
				src/utils.c

all:$(NAME)

$(NAME): $(SRC) $(INCLUDE)
	mkdir -p bin
	make -C $(MLX_PATH) 2>/dev/null
	make -C $(LIBFT_PATH) 
	make -C $(FT_PRINTF_PATH)
	mv $(MLX_PATH)/libmlx.a bin/
	mv $(LIBFT_PATH)/libft.a bin/
	mv $(FT_PRINTF_PATH)/libftprintf.a bin/
	cc  $(CFLAGS) $(MLX_CF) bin/libmlx.a bin/libft.a bin/libftprintf.a $(SRC) -o $(NAME) 

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean
	make -C $(FT_PRINTF_PATH) clean
	make -C $(MLX_PATH) clean
	rm -rf obj	
	rm -rf bin
fclean: clean
	rm -rf $(NAME)
	
re: clean all 
.PHONY: all clean fclean re