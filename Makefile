# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 18:06:49 by anjose-d          #+#    #+#              #
#    Updated: 2022/02/14 21:52:16 by anjose-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### FIRST TO BE EXECUTED
.DEFAULT_GOAL	=	all

### FINAL BINARY
NAME		=	so_long
BNS_NAME	=	so_long

### DIRECTORIES
DIR_SRCS	=	./srcs
DIR_INCS	=	./includes
HEADER		=	$(DIR_INCS)/so_long.h
DIR_OBJS	=	./objs

### STATIC LIBRARIES
LIBFT		=	ft
DIR_LIBFT	=	./libft
INC_LIBFT	=	-L$(DIR_LIBFT) -l$(LIBFT)
MLX			=	mlx
DIR_MLX		=	./minilibx
INC_MLX		=	-L$(DIR_MLX) -l$(MLX) -lXext -lX11

### COMPILATION DETAILS
CC			=	gcc -g3
CFLAGS		=	-Wall -Wextra -Werror
INCFLAGS	=	-I $(DIR_INCS) -I $(DIR_MLX)
DBGFLAGS	=	-g

### SRC AND OBJ NAME FILES
MAIN		=	main.c

SRCS		=	$(MAIN) \
				check_utils.c \
				init_struct.c init_game.c init_imgs.c \
				map_read.c map_check.c map_borders_check.c map_save.c \
				game_end.c \
				hooks_load_game.c hooks_key_mapping.c

DIR_GUARD	=	mkdir -p $(@D)

OBJS		=	$(addprefix $(DIR_OBJS)/, $(SRCS:.c=.o))

### PATH TO SRC FILES
PATH_SRCS	=	$(addprefix $(DIR_SRCS)/, $(SRCS))

### BONUS
BNS_HEADER	=	$(DIR_INCS)/so_long_bonus.h
DIR_SRCBNS	=	./bonus_srcs
SRCS_BONUS	=	main_bonus.c \
				check_utils_bonus.c \
				init_struct_bonus.c init_game_bonus.c init_imgs_bonus.c \
				map_read_bonus.c map_check_bonus.c map_borders_check_bonus.c map_save_bonus.c \
				game_end_bonus.c \
				hooks_load_game_bonus.c hooks_key_mapping_bonus.c
OBJS_BONUS	=	$(addprefix $(DIR_OBJS)/, $(SRCS_BONUS:.c=.o))
PATH_SRCSBNS=	$(addprefix $(DIR_SRCBNS)/, $(SRCS_BONUS))

### TARGETS
# MANDATORY
$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c $(HEADER)
	$(DIR_GUARD)
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

# BONUS
$(DIR_OBJS)/%.o: $(DIR_SRCBNS)/%.c $(BNS_HEADER)
	$(DIR_GUARD)
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(DIR_LIBFT)
	make -C $(DIR_MLX)
	$(CC) $(CFLAGS) $(INCFLAGS) $^ $(INC_LIBFT) $(INC_MLX) -o $@
	@echo "Done!"

all: $(NAME)

clean:
	rm -rf $(DIR_OBJS)
	rm -rf $(OBJS_BONUS)
	rm -f debug debug_bonus
	make $@ -C $(DIR_LIBFT)
	make $@ -C $(DIR_MLX)

fclean: clean
	rm -f $(NAME)
	rm -f $(BNS_NAME)
	make $@ -C $(DIR_LIBFT)

re: fclean all

run: all
	./$(NAME) maps/valid_map1.ber

run_bonus: bonus
	./$(NAME) maps/bonus_valid_map1.ber

bonus: $(OBJS_BONUS)
	@make OBJS="$(OBJS_BONUS)" all

debug: $(PATH_SRCS)
	$(CC) $(CFLAGS) $(INCFLAGS) $(DBGFLAGS) $^ $(INC_LIBFT) $(INC_MLX) -o $@
	gdb --tui ./$@

debug_bonus: $(PATH_SRCSBNS)
	$(CC) $(CFLAGS) $(INCFLAGS) $(DBGFLAGS) $^ $(INC_LIBFT) $(INC_MLX) -o $@
	gdb --tui ./$@

norm:
	norminette $(DIR_SRCS) $(DIR_INCS) $(DIR_LIBFT) $(DIR_SRCBNS)

valgrind:
	$@ $(VALGFLAGS) --leak-check=full -s --show-leak-kinds=all --track-origins=yes --tool=memcheck ./$(NAME) maps/valid_map1.ber

valgrind_bonus:
	valgrind $(VALGFLAGS) --leak-check=full -s --show-leak-kinds=all --track-origins=yes --tool=memcheck ./$(NAME) maps/bonus_valid_map1.ber

$(LIBFT):
	make -C $(DIR_LIBFT)

$(MLX):
	make -C $(DIR_MLX)

.PHONY: all clean fclean re debug debug_bonus norm valgrind valgrind_bonus bonus run_bonus run
