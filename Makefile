NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = ./includes
LIBFT_DIR = ./libft
MLX_DIR = ./mlx_linux
SRC_DIR		= ./src/
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx_Linux.a
LIBFT_INC = -I$(INCLUDES)
MLX_PATH = /usr/include
MLX_INC = -I$(MLX_PATH)

# Source files and object files
SRC_FILES	= so_long map_generator map_generator_utils \
			ft_utils ft_move_actions
SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(SRC:.c=.o)

# Main target
all: submodule $(NAME)

# Initialize submodule
submodule:
	git submodule update --init --recursive

# To link with the required internal Linux API:
$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(OBJ) $(LIBFT) $(MLX) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INC) -Imlx_linux -O3 -c $< -o $@ $(LIBFT_INC)

# Compile mlx
$(MLX):
	make -C $(MLX_DIR)

# Compile libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Clean object files
clean:
	rm -f $(OBJ)
	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT_DIR)

# Clean object files and executables
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

# Recompile everything
re: fclean all
