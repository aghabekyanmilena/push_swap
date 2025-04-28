NAME = push_swap
SRC_DIR = src
INC_DIR = includes
BON_DIR = bonus
BONUS = checker
LIBFT_DIR = libft

SRC = $(SRC_DIR)/main.c $(SRC_DIR)/validation.c $(SRC_DIR)/init.c $(SRC_DIR)/functions.c $(SRC_DIR)/operations_a.c \
			$(SRC_DIR)/operations_b.c $(SRC_DIR)/sorting.c $(SRC_DIR)/arr.c $(SRC_DIR)/arr1.c $(SRC_DIR)/print.c \
			$(SRC_DIR)/functions1.c $(SRC_DIR)/butterfly.c

BSRC = $(SRC_DIR)/bonus.c $(SRC_DIR)/get_next_line.c $(SRC_DIR)/get_next_line_utils.c $(SRC_DIR)/validation.c \
			$(SRC_DIR)/init.c $(SRC_DIR)/functions.c $(SRC_DIR)/operations_a.c \
			$(SRC_DIR)/operations_b.c $(SRC_DIR)/sorting.c $(SRC_DIR)/arr.c $(SRC_DIR)/arr1.c $(SRC_DIR)/print.c \
			$(SRC_DIR)/functions1.c $(SRC_DIR)/butterfly.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) -I $(LIBFT_DIR) # -fsanitize=address -g3

LIBFT_LIB = $(LIBFT_DIR)/libft.a
RM = rm -f

all: $(NAME)

bonus: $(BONUS)

$(BONUS): $(BSRC) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(BSRC) $(LIBFT_LIB) -o $(BONUS)

$(NAME): $(SRC) $(LIBFT_LIB) 
	$(CC) $(CFLAGS) $(SRC) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) 
	$(RM) $(BONUS)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus