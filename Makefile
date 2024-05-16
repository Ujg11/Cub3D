# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 13:54:24 by agrimald          #+#    #+#              #
#    Updated: 2024/05/16 16:29:40 by ojimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d👾
CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address

INCS = -I./include/ -I./include/Libft
LIBFTA = -L./include/Libft -lft
SRCDIR = src/
OBJDIR = obj/

SRC_L =	main.c \
		parser/check_coordinates.c \
		parser/check_map.c \
		parser/clean.c \
		parser/extension.c \
		parser/fds.c \
		parser/info_map.c \
		parser/map_close.c \
		parser/parser.c \
		parser/utils.c \
		parser/utils_2.c \
		parser/utils_3.c \
		parser/valid_map.c \
		raytracing/init_graphics.c \
		raytracing/init_cub.c raytracing/init_mlx.c raytracing/do_cub.c raytracing/raycasting.c \
		raytracing/textures.c raytracing/read_keys.c raytracing/destroy.c raytracing/utils.c raytracing/orientation.c
		

#raytracing/map2.c
		
SRC = $(addprefix $(SRCIR), $(SRC_L))
OBJECTS = $(addprefix $(OBJDIR), $(SRC:.c=.o))

#configuracion para MLX
MLX = -L./include/mlx -lmlx -framework OpenGL -framework AppKit
INCS += -I./include/mlx

all: $(NAME)

$(OBJDIR)%.o: %.c
			@printf "\033[1;36m\nCompiling objects baby 🤭\033[0m\n"
			@mkdir -p $(@D)
			@gcc $(CFLAGS) $(INCS) -c $< -o $@

$(NAME): $(OBJECTS) Makefile include/cub3d.h
			@mkdir -p $(@D)
			@gcc $(CFLAGS) -o $@ $(OBJECTS) $(LIBFTA) $(MLX)
			@printf "\033[1;35m\nCompiled successfully 🥵!!!\033[0m\n"

fclean: clean
		@rm -rf $(NAME)

clean:
		@rm -rf $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re
