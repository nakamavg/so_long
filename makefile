NAME		:= so_long
MLX_CF		:= -framework OpenGL -framework AppKit
CFLAGS		:= -Wall -Wextra -Werror -fsanitize=address -Ilib/libft
MLX_PATH	:= lib/mlx
LIBFT_PATH	:= lib/libft
FT_PRINTF_PATH	:= lib/ft_printf
INCLUDE 	:= ./src/so_long.h
SRC 		:= $(wildcard src/*.c)
OBJ			:= $(SRC:src/%.c=%.o)

all:$(NAME)

$(NAME):$(OBJ)
	mkdir -p bin
	make -C $(MLX_PATH) 2>/dev/null
	make -C $(LIBFT_PATH) 
	make -C $(FT_PRINTF_PATH)
	mv $(MLX_PATH)/libmlx.a bin/
	mv $(LIBFT_PATH)/libft.a bin/
	mv $(FT_PRINTF_PATH)/libftprintf.a bin/
	gcc $(OBJ) $(CFLAGS) $(MLX_CF) bin/*.a -o $(NAME) && ./so_long map.ber

$(OBJ):%.o:src/%.c $(INCLUDE)
	gcc -c $< -o $@ 

clean:
	rm -rf $(OBJ) $(NAME)
	make -C $(MLX_PATH) clean
	
	rm -rf bin
fclean: clean
	rm -rf $(NAME)
re: clean all 
#norminette src/*.c 
