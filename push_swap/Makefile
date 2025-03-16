NAME :=  push_swap
CC := cc
CFLAGS := -Wall -Wextra -Werror
LIBFT := libft/libft.a
LIBFT_DIR := libft

SRC_DIR := src
SRCS := $(shell find $(SRC_DIR) -name "*.c")
OBJS := $(SRCS:.c=.o)

INCLUDES := -I lib -I $(LIBFT_DIR)

# Colors for output
GREEN := \033[0;32m
YELLOW := \033[0;33m
RESET := \033[0m

all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "$(YELLOW)Compiling Libft...$(RESET)"
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(YELLOW)Removing executable and libft...$(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re