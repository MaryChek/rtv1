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

CC = gcc
FLAGS = -g -O2
GRAF_FLAGS = -framework OpenGL -framework AppKit

LIBS = -L $(LIBFT_DIR) -lft -L $(MINILIBX_DIR) -lmlx -lm $(GRAF_FLAGS)
INCLUDES = -I $(LIBFT_DIR) -I $(MINILIBX_DIR) -I $(H_DIR)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_H = $(LIBFT_DIR)

MINILIBX = $(MINILIBX_DIR)libmlx.a
MINILIBX_DIR = ./minilibx/
MINILIBX_H = $(MINILIBX_DIR)

H_FILE = rtv1.h
H_DIR = ./header/
HEADER = $(addprefix $(H_DIR), $(H_FILE))

SRC_DIR = ./src/
SRC_FILES = main.c allocation.c camera.c color.c draw.c errors.c figure.c \
			grafic_connection.c hooks_and_deals.c light.c \
			light_and_shadow.c no_name.c normal_to_obj.c presets.c \
			param_validation.c quadratic_equation.c quater_rotation.c \
			ray_trace.c tear_down.c read_file.c read_utils.c vectors.c \


SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR = ./src/objects/
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ_DIR) $(OBJ)
	@$(CC) $(FLAGS) $(LIBS) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "------------RTv1 compiled!---------------"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADER)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)
	@echo "------------make libft finish------------"

$(MINILIBX):
	@$(MAKE) -sC $(MINILIBX_DIR)
	@echo "------------make minilibx finish------------"

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(MINILIBX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "------------clean finish------------"

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(MINILIBX)
	@rm -f $(NAME)
	@echo "------------fclean finish------------"

re:
	@$(MAKE) fclean
	@$(MAKE) all
	@echo "------------fclean all finish------------"
