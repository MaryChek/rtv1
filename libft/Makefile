# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: dtaisha <dtaisha@student.21-school.ru>     +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/05/05 11:42:06 by dtaisha           #+#    #+#             #
#   Updated: 2020/10/08 23:14:18 by dtaisha          ###   ########lyon.fr   #
#                                                                            #
# ************************************************************************** #


NAME = libft.a

SRC = ft_strncmp.c ft_memalloc.c ft_strcat.c ft_strncpy.c ft_bzero.c \
	  ft_memccpy.c ft_strchr.c ft_strnequ.c ft_isalnum.c ft_memchr.c \
	  ft_strclr.c ft_strnew.c ft_isalpha.c ft_memcmp.c ft_strcmp.c \
	  ft_strnstr.c ft_isascii.c ft_memcpy.c ft_strcpy.c ft_strrchr.c \
	  ft_isdigit.c ft_memdel.c ft_strdel.c ft_strsplit.c ft_isprint.c \
	  ft_memmove.c ft_strdup.c ft_strstr.c ft_itoa.c ft_memset.c ft_strequ.c \
	  ft_strsub.c ft_putchar.c ft_striter.c ft_strtrim.c ft_putchar_fd.c \
	  ft_striteri.c ft_tolower.c ft_putendl.c ft_strjoin.c ft_toupper.c \
	  ft_putendl_fd.c ft_strlcat.c ft_putnbr.c ft_strlen.c ft_atoi.c \
	  ft_putnbr_fd.c ft_strmap.c ft_putstr.c ft_strmapi.c ft_arrlen.c\
	  ft_putstr_fd.c ft_strncat.c ft_free_arr.c ft_cnt_l.c ft_cnt_w.c \
	  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	  ft_lstmap.c ft_free_list.c get_next_line.c ft_free.c ft_izero.c\
	  ft_is_hex.c ft_atoi_base.c ft_is_space.c ft_swap.c ft_to_digit.c \
	  ft_safe_free_arr.c ft_cnt_digits.c

FT_O = $(SRC:.c=.o)

INC = libft.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC) $(FT_O)
	ar rc $(NAME) $(FT_O)
	ranlib $(NAME)

$(FT_O): %.o: %.c
	gcc -c -Wall -Wextra -Werror $< -I $(INC)

clean:
	rm -rf $(FT_O)

fclean: clean
	rm -rf $(NAME)

re: fclean all
