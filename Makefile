NAME = push_swap
NAME_BONUS = checker

LIBFT = libft/libft.a
LIBFT_DIR = libft/

INC_DIR = include/
OBJ_DIR = obj/
SRC_DIR = src/
BONUS_DIR = bonus/

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I $(LIBFT_DIR) -I $(INC_DIR) -g
LIBFLAGS = -lft
CC = cc
RM = rm -fr

FILES = main.c
FILES += init.c
FILES += exit.c
FILES += sort.c
FILES += sorting_utils.c
FILES += language.c
FILES += stack.c
FILES += best.c
FILES += check.c
FILES += swap.c
SRC = $(addprefix $(SRC_DIR), $(FILES))
OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

FILES_BONUS = main_bonus.c
FILES_BONUS += init.c
FILES_BONUS += exit.c
FILES_BONUS += sort.c
FILES_BONUS += sorting_utils.c
FILES_BONUS += language.c
FILES_BONUS += stack.c
FILES_BONUS += best.c
FILES_BONUS += check.c
FILES_BONUS += swap.c
SRC_BONUS = $(addprefix $(BONUS_DIR), $(FILES_BONUS))
OBJ_BONUS = $(addprefix $(OBJ_DIR), $(FILES_BONUS:.c=.o))

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
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

bonus: $(NAME_BONUS)

$(OBJ_DIR)%.o: $(BONUS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_BONUS): $(OBJ_DIR) $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) -L $(LIBFT_DIR) $(LIBFLAGS)

rebonus: fclean bonus

norm:
	@clear
	@norminette | grep Error || true

test:
	@bash test/test.sh

.PHONY: all clean fclean re bonus rebonus norm test
