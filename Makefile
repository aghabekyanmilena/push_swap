NAME = push_swap
SRC_DIR = src
INC_DIR = includes
LIBFT_DIR = libft

SRC = $(SRC_DIR)/main.c $(SRC_DIR)/validation.c $(SRC_DIR)/init.c $(SRC_DIR)/functions.c $(SRC_DIR)/operations_a.c \
			$(SRC_DIR)/operations_b.c $(SRC_DIR)/sorting.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) -I $(LIBFT_DIR) # -fsanitize=address

LIBFT_LIB = $(LIBFT_DIR)/libft.a
RM = rm -f

all: $(NAME)

$(NAME): $(SRC) $(LIBFT_LIB) 
	$(CC) $(CFLAGS) $(SRC) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re