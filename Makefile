# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 13:51:15 by abiri             #+#    #+#              #
#    Updated: 2018/11/15 14:28:51 by abiri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FDFFILES = ft_fdf_lists.c\
	ft_fdf_parse.c\
	ft_iso_projection.c\
	ft_mlx_engine.c\
	ft_pixels.c\
	ft_rotate.c\
	design.c\
	./get_next_line/get_next_line.c\
	main.c

LIBDIRS = -L./libft -L./minilibx -L./libft/ft_printf
LIBS = -lft -lftprintf -lmlx
INCLUDES = -I libft -I get_next_line -I libft/ft_printf
FLAGS = -framework OpenGl -framework AppKit

all: $(NAME)
$(NAME):
	gcc $(FDFFILES) $(INCLUDES) $(LIBDIRS) $(LIBS) $(FLAGS) -o $(NAME)
clean:
	rm -f $(NAME)
fclean: clean
re: fclean all
