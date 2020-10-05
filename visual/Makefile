# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/18 15:55:20 by acarlett          #+#    #+#              #
#    Updated: 2020/10/04 20:31:39 by acarlett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS =		-Wall -Werror -Wextra

DIR_SRC =	srcs

DIR_LIB =	../libft

DIR_INC =	includes

NAME =		visualizer

FRAME = -I./frameworks/SDL2_image.framework/Versions/A/Headers

SDL_INC := -F./SDL/frameworks \
		-rpath SDL/frameworks \
		-framework SDL2 \
		-framework SDL2_image

LIB_NAME =	$(DIR_LIB)/libft.a

INC_NAME =	$(DIR_INC)/visualizer.h

SOURCES =	$(DIR_SRC)/background_graph.c \
			$(DIR_SRC)/draw_links.c \
			$(DIR_SRC)/draw_nodes.c \
			$(DIR_SRC)/draw_ants.c \
			$(DIR_SRC)/main.c \
			$(DIR_SRC)/min_max_coords.c \
			$(DIR_SRC)/random.c \
			$(DIR_SRC)/render_load_surface.c \
			$(DIR_SRC)/v_parse_ants_number.c \
			$(DIR_SRC)/v_parse_links.c \
			$(DIR_SRC)/v_parse_map.c \
			$(DIR_SRC)/v_parse_rooms.c \
			$(DIR_SRC)/v_parse_path.c \
			$(DIR_SRC)/v_deleting.c \
			$(DIR_SRC)/v_checkers.c \
			$(DIR_SRC)/v_adjacency_matrix.c \
			$(DIR_SRC)/work_with_coords.c 

OBJECTS =	$(patsubst %.c,%.o,$(SOURCES))

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(DIR_LIB)
	@cc -o $(NAME) $(SOURCES) -I $(DIR_INC) $(SDL_INC) $(FRAME) $(LIB_NAME)

%.o: %.c $(INC_NAME)
	@cc -I $(DIR_INC) $< -c -o $@

clean:
	@make -C $(DIR_LIB) clean
	@rm -rf $(OBJECTS)

fclean: clean
	@make -C $(DIR_LIB) fclean
	@rm -rf $(NAME)

re: fclean all