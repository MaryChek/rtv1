cmake_minimum_required(VERSION 3.15)
project(rtv1 C)

set(CMAKE_C_STANDARD 11)


include_directories(header/)
include_directories(libft/)
include_directories(src/graphics/)
include_directories(src/main/)
include_directories(src/parsing/)
include_directories(minilibx/)
include_directories(scenes/)


add_executable(rtv1
        header/rtv1.h
        minilibx/
        src/
        src/parsing/allocation.c
        src/parsing/hooks_and_deals.c
        src/parsing/param_validation.c
        src/parsing/errors.c
        src/graphics/ray_trace.c
        src/main/main.c
        src/parsing/tear_down.c
        libft/ft_strchr.c
        libft/ft_bzero.c
        libft/ft_strcmp.c
        libft/ft_strlen.c
        libft/ft_strsplit.c
        libft/ft_putstr.c
        libft/ft_strsub.c
        libft/ft_strsplit.c
        libft/ft_isdigit.c
        libft/ft_memcpy.c
        libft/ft_memcmp.c
        libft/ft_memset.c
        libft/ft_strdup.c
        libft/libft.h
        libft/ft_atoi.c
        libft/ft_memccpy.c
        libft/ft_strcmp.c
        libft/ft_memdel.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strrchr.c
        libft/ft_strclr.c
        libft/ft_strcpy.c
        libft/ft_strdel.c
        libft/ft_strjoin.c
        libft/ft_strlcat.c
        libft/ft_strncat.c
        libft/ft_strnew.c
        libft/ft_strnstr.c
        libft/ft_bzero.c
        src/parsing/read_utils.c
        src/graphics/color.c
        src/parsing/camera.c
        src/parsing/figure.c
        src/parsing/light.c
        src/graphics/light_and_shadow.c
        src/graphics/no_name.c
        src/graphics/normal_to_obj.c
        src/graphics/quadratic_equation.c
        src/graphics/quater_rotation.c
        src/graphics/vectors.c src/graphics/grafic_connection.c src/parsing/presets.c src/graphics/draw.c src/graphics/color.c src/graphics/quater_rotation.c src/parsing/read_file.c)
