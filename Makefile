# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 18:06:49 by anjose-d          #+#    #+#              #
#    Updated: 2022/02/05 11:11:24 by anjose-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### FIRST TO BE EXECUTED
.DEFAULT_GOAL	=	all

### FINAL BINARY
NAME		=	so_long

### DIRECTORIES
DIR_SRCS	=	./srcs
DIR_INCS	=	./includes
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
CFLAGS		=	-Wall -Werror -Wextra -I $(DIR_INCS) -I $(DIR_MLX)
DBGFLAGS	=	-g
VALGFLAGS	=	-g3

### SRC AND OBJ NAME FILES
MAIN		=	main.c

SRCS		=	$(MAIN) \
				error_check.c \
				init_struct.c init_game.c init_imgs.c \
				map_read.c map_check.c map_borders_check.c map_save.c \
				game_end.c \
				hooks_load_imgs.c



OBJS		=	$(SRCS:.c=.o)

### PATH TO SRC AND OBJ FILES
PATH_SRCS	=	$(addprefix $(DIR_SRCS)/, $(SRCS))
PATH_OBJS	=	$(addprefix $(DIR_OBJS)/, $(OBJS))

### TARGETS
$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(PATH_OBJS)
	make -C $(DIR_LIBFT)
	make -C $(DIR_MLX)
	$(CC) $(CFLAGS) $^ $(INC_LIBFT) $(INC_MLX) -o $@
	@echo "Done!"

all: $(NAME)

clean:
	rm -f $(PATH_OBJS)
	make $@ -C $(DIR_LIBFT)
	make $@ -C $(DIR_MLX)

fclean: clean
	rm -f $(NAME)
	make $@ -C $(DIR_LIBFT)

re: fclean all

debug: $(PATH_SRCS)
	$(CC) $(CFLAGS) $(DBGFLAGS) $^ $(INC_LIBFT) $(INC_MLX) -o $@
	gdb --tui ./$@

norm:
	norminette $(DIR_SRCS) $(DIR_INCS) $(DIR_LIBFT)

valgrind:
	$@ --leak-check=full -s --show-leak-kinds=all --tool=memcheck ./$(NAME) maps/valid_map1.ber

$(LIBFT):
	make -C $(DIR_LIBFT)

$(MLX):
	make -C $(DIR_MLX)

.PHONY: all clean fclean re debug norm valgrind