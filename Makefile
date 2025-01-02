# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 17:41:33 by aalahyan          #+#    #+#              #
#    Updated: 2025/01/02 12:25:37 by aalahyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR=libft
LIBFT=$(LIBFT_DIR)/libft.a
CC=cc
CFLAGS= -Wall -Wextra -Werror
NAME=push_swap
MANDATORY_DIR=mandatory
BONUS_DIR=bonus
BIN_DIR=bin
CHECKER=checker
HEADERFILE=$(MANDATORY_DIR)/push_swap.h
MANDATORY_SRCS=	$(MANDATORY_DIR)/main.c \
				$(MANDATORY_DIR)/parse_arguments.c \
				$(MANDATORY_DIR)/free_memory.c \
				$(MANDATORY_DIR)/booleans.c \
				$(MANDATORY_DIR)/assets.c \
				$(MANDATORY_DIR)/init_stack.c \
				$(MANDATORY_DIR)/stack_manipulation.c \
				$(MANDATORY_DIR)/push_swap.c \
				$(MANDATORY_DIR)/phase_1.c \
				$(MANDATORY_DIR)/phase_2.c \
				$(MANDATORY_DIR)/sorting_helpers.c \
				$(MANDATORY_DIR)/init_positions.c \

BONUS_SRCS=	$(BONUS_DIR)/parse_arguments_bonus.c \
			$(BONUS_DIR)/free_memory_bonus.c \
			$(BONUS_DIR)/booleans_bonus.c \
			$(BONUS_DIR)/assets_bonus.c \
			$(BONUS_DIR)/main_bonus.c \
			$(BONUS_DIR)/init_stack_bonus.c \
			$(BONUS_DIR)/stack_operations_bonus.c \
			$(BONUS_DIR)/checker_bonus.c

MANDATORY_OBJS = $(MANDATORY_SRCS:$(MANDATORY_DIR)/%.c=$(BIN_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:$(BONUS_DIR)/%.c=$(BIN_DIR)/%.o)

all: $(NAME)
	@echo "\033[1;32m>>Push_swap is up to date!\033[0m"

bonus: $(CHECKER)
	@echo "\033[1;32m>>Checker is up to date!\033[0m"

inform:
	@echo "\033[1;33m>>Compiling mandatory...\033[0m"

inform_bonus:
	@echo "\033[1;33m>>Compiling bonus...\033[0m"

$(NAME): $(LIBFT) $(BIN_DIR) inform $(MANDATORY_OBJS) $(HEADERFILE)
	@$(CC) $(CFLAGS) $(MANDATORY_OBJS) -L$(LIBFT_DIR) -lft -o $@

$(CHECKER): $(LIBFT) $(BIN_DIR) inform_bonus $(BONUS_OBJS) $(HEADERFILE)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -o $@

$(BIN_DIR):
	@mkdir $(BIN_DIR)
$(LIBFT):
	@make -C $(LIBFT_DIR)

$(BIN_DIR)/%.o: $(BONUS_DIR)/%.c $(HEADERFILE)
	@$(CC) $(CFLAGS) -c $< -o $@
$(BIN_DIR)/%.o: $(MANDATORY_DIR)/%.c $(HEADERFILE)
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	@rm -rf $(BIN_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "\033[1;31m>>cleaned!\033[0m"

fclean: clean
	@rm -rf $(NAME)  $(CHECKER)
	@make fclean -C $(LIBFT_DIR)
re: fclean all