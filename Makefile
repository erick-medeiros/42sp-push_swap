NAME = push_swap

LIBFT = libft/libft.a
LIBFT_DIR = libft/

INC_DIR = include/
OBJ_DIR = obj/
SRC_DIR = src/

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I $(LIBFT_DIR) -I $(INC_DIR) -g
LIBFLAGS = -lft
CC = cc
RM = rm -fr

FILES = main.c
FILES += exit.c
FILES += sort.c
FILES += language.c
FILES += stack.c
SRC = $(addprefix $(SRC_DIR), $(FILES))
OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_DIR) $(LIBFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	@clear
	@norminette | grep Error || true

test:
	@bash test/test.sh

.PHONY: all clean fclean re norm test