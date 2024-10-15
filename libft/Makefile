# Name of the library
NAME = libft.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)
PRINTF_DIR		= $(SRC_DIR)ft_printf/
SRC_DIR		= ./

# Include directory
INCLUDES = ../includes

# Source files and object files
SRC_FILES	= ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
		ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy \
		ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr \
		ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup \
		ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi \
		ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
		get_next_line
PRINTF_FILES	=	ft_printf ft_print_decimal ft_print_num_hex ft_print_pointer ft_print_str ft_puthex  ft_un_decimal
SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES))) \
		$(addprefix $(PRINTF_DIR), $(addsuffix .c, $(PRINTF_FILES)))
OBJ = $(SRC:.c=.o)

# Main target
all: $(NAME)

# Compile the library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Compile object files, using INCLUDES for header files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)

# Clean object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild the library from scratch
re: fclean all

# Phony targets to prevent conflicts
.PHONY: all clean fclean re
