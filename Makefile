NAME = fractol
SRC_DIR = src
INC_DIR = includes
LIBFT_DIR = libft

SRC = $(SRC_DIR)
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) -I $(LIBFT_DIR) # -fsanitize=address 

LIBFT_LIB = $(LIBFT_DIR)/libft.a
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB) 
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

%.o: %.c $(INC_DIR)/push_swap.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re