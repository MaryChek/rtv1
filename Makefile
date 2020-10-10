# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: dtaisha <dtaisha@student.21-school.ru>     +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/05/09 19:47:36 by dtaisha           #+#    #+#             #
#   Updated: 2020/10/09 02:57:14 by dtaisha          ###   ########lyon.fr   #
#                                                                            #
# ************************************************************************** #

NAME = rtv1

CFLAGS = -g

CC = clang

MLX = -lmlx -framework OpenGL -framework AppKit

COMP = $(CC) $(CFLAGS) $(INCLUDES)

LIBFT_DIR = libft/
LIBFT_H = -I $(LIBFT_DIR)
LIBFT_A = libft.a
LIBFT = $(LIBFT_DIR)$(LIBFT_A)

HEAD_DIR = header/
RTV1_H = -I $(HEAD_DIR)
HEAD = $(HEAD_DIR)rtv1.h

INCLUDES = $(LIBFT_H) $(RTV1_H)

SRC_DIR = src/
GRAPH_DIR = $(SRC_DIR)graphics/
PARS_DIR = $(SRC_DIR)parsing/
MAIN_DIR = $(SRC_DIR)main/


MAIN_FILE = 	main.c
GRAPHICS_FILES = color.c light_and_shadow.c \
				no_name.c normal_to_obj.c \
				quadratic_equation.c  ray_trace.c \
				quater_rotation.c vectors.c
PARSING_FILES = allocation.c camera.c \
				draw.c errors.c figure.c \
				grafic_connection.c light.c \
				hooks_and_deals.c read_utils.c \
				presets.c param_validation.c \
				tear_down.c read_file.c

SRC_FILES = $(MAIN_FILE) $(GRAPHICS_FILES) $(PARSING_FILES)

OBJ_DIR = obj/

OBJ_FILE =	$(SRC_FILES:.c=.o)

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILE))

all: lib $(NAME)

lib:
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ) $(HEAD)
	@$(COMP) $(LIBFT) $(MLX) $(OBJ) -o $(NAME)
	@echo "-----------compiled rtv1 finish----------"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "-----------mkdir OBJ_DIR finish----------"

$(OBJ_DIR)%.o: $(GRAPH_DIR)%.c $(HEAD)
	@$(COMP) -c $< -o $@


$(OBJ_DIR)%.o: $(PARS_DIR)%.c $(HEAD)
	@$(COMP) -c $< -o $@

$(OBJ_DIR)%.o: $(MAIN_DIR)%.c $(HEAD)
	@$(COMP) -c $< -o $@

# $(MINILIBX):
# 	@echo "------------make minilibx finish------------"
# 	@$(MAKE) -sC $(MINILIBX_DIR)

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
# @$(MAKE) -sC $(MINILIBX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "---------------clean finish--------------"

fclean: clean
	@rm -f $(LIBFT)
# @rm -f $(MINILIBX)
	@rm -f $(NAME)
	@echo "--------------fclean finish--------------"

re:
	@$(MAKE) fclean
	@$(MAKE) all
	@echo "------------fclean all finish------------"
