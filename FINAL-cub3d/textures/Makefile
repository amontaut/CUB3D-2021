SRC =	main.c \
		gnl.c \
		exits.c \
		exits_2.c \
		ft_itoa.c \
		utils_1.c \
		utils_2.c \
		raycast_loop.c \
		init_values_1.c \
		init_values_2.c \
		checks_CF.c \
		move_up_down_up_down_cam.c \
		fill_check_TCF.c \
		fill_path_TCF.c \
		strmap.c \
		gnl_in_str.c \
		map_double_char.c \
		key_raycast_posxy.c \
		malloc_text_check_walls.c \

NAME = Cub3D

MLX_DIR = minilibx-linux
MLX = libmlx.a 
CC = clang

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = include

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
DPD = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.d))

.c.o:
	${CC} ${CFLAGS} -c$< -o ${<:.c=.o}

all:
	@$(MAKE) -j $(NAME)

$(NAME): $(OBJ)
		${CC} $(CFLAGS) -o $(NAME) $(OBJ) -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext
		@echo $(NAME) : Created !

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | .gitignore
		@mkdir -p $(OBJ_DIR)
		${CC} $(CFLAGS) -I $(INC_DIR) -I $(MLX_DIR) -c $< -o $@


clean:
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re

-include $(DPD)