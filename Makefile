NAME = rtv1

LIB_DIR = libft/

LIBFT_H = -I $(LIB_DIR)

LIBFTA = libft.a

RTV1_H = -I header/

HEAD = header/rtv1.h

SRC_DIR = src/

SRCS = main.c ray_trace.c color.c vectors.c\
quadratic_equation.c key_press.c light_and_shadow.c \
quater_rotation.c normal_to_obj.c no_name.c

CFIND =	$(SRCS:%=$(SRC_DIR)%)

OBJ_DIR =	obj/

OFILE =	$(SRCS:%.c=%.o)

OBJ =	$(addprefix $(OBJ_DIR), $(OFILE))

CFLAGS = -g

CC = clang

MLX = -lmlx -framework OpenGL -framework AppKit

OPENCL = -framework OpenCL

COMP =	$(CC) $(CFLAGS) $(RTV1_H) $(LIBFT_H) $(LIB_DIR)$(LIBFTA)

all: $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEAD)
		@$(CC) $(CFLAGS) $(RTV1_H) $(LIBFT_H) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)$(LIBFTA) .
	@mv $(LIBFTA) $(NAME)
	$(COMP) $(MLX) $(OPENCL) $(addprefix $(SRC_DIR), $(SRCS)) -o $(NAME)

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(LIB_DIR) clean
	@echo OBJECTS FILES HAS BEEN DELETED.

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIB_DIR) fclean
	@echo OBJECT FILES AND EXECUTABLE HAS BEEN DELETED.

re: fclean all
