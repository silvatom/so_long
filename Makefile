# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 18:06:49 by anjose-d          #+#    #+#              #
#    Updated: 2022/02/11 05:57:34 by anjose-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### FIRST TO BE EXECUTED
.DEFAULT_GOAL	=	all

### FINAL BINARY
NAME		=	so_long

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
CC			=	gcc
CFLAGS		=	
INCFLAGS	=	-I $(DIR_INCS) -I $(DIR_MLX)
DBGFLAGS	=	-g

### SRC AND OBJ NAME FILES
MAIN		=	main.c

SRCS		=	$(MAIN) \
				error_check.c \
				init_struct.c init_game.c init_imgs.c \
				map_read.c map_check.c map_borders_check.c map_save.c \
				game_end.c \
				hooks_load_game.c hooks_key_mapping.c

DIR_GUARD	=	mkdir -p $(@D)

OBJS		=	$(addprefix $(DIR_OBJS)/, $(SRCS:.c=.o))

### PATH TO SRC FILES
PATH_SRCS	=	$(addprefix $(DIR_SRCS)/, $(SRCS))

### BONUS
BNS_NAME	=	$(NAME)_bonus
BNS_HEADER	=	$(DIR_INCS)/so_long_bonus.h
DIR_SRCBNS	=	./bonus_srcs
SRCS_BONUS	=	bonus_$(MAIN) \
				bonus_error_check.c \
				bonus_init_struct.c bonus_init_game.c bonus_init_imgs.c \
				bonus_map_read.c bonus_map_check.c bonus_map_borders_check.c bonus_map_save.c \
				bonus_game_end.c \
				bonus_hooks_load_game.c bonus_hooks_key_mapping.c
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
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	rm -f debug debug_bonus
	make $@ -C $(DIR_LIBFT)
	make $@ -C $(DIR_MLX)
	

fclean: clean
	rm -f $(NAME)
	rm -f $(BNS_NAME)
	make $@ -C $(DIR_LIBFT)

re: fclean all

bonus: $(OBJS_BONUS)
	make -C $(DIR_LIBFT)
	make -C $(DIR_MLX)
	$(CC) $(CFLAGS) $(INCFLAGS) $^ $(INC_LIBFT) $(INC_MLX) -o $(BNS_NAME)

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
	valgrind $(VALGFLAGS) --leak-check=full -s --show-leak-kinds=all --track-origins=yes --tool=memcheck ./$(BNS_NAME) maps/valid_map1.ber

$(LIBFT):
	make -C $(DIR_LIBFT)

$(MLX):
	make -C $(DIR_MLX)

.PHONY: all clean fclean re debug debug_bonus norm valgrind valgrind_bonus bonus 
