NAME		:= push_swap

# Directories
SRC_DIR		:= src
OBJ_DIR		:= obj
LIBFT_DIR	:= libft

# Files
SRC			:= $(addprefix $(SRC_DIR)/, \
	algorithm.c check.c free.c move.c push.c swap.c reverse.c parse.c rotate.c\
	algorithm_helper.c cost.c init.c operations.c arg.c	exit.c	main.c utils.c target.c)

OBJ			:= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compiler & Flags
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -I. -I$(LIBFT_DIR)

# Libft
LIBFT		:= $(LIBFT_DIR)/libft.a

# Colors (optional)
GREEN		:= \033[0;32m
RESET		:= \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)✓ push_swap compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
