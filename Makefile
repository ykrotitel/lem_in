# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/14 21:30:04 by acarlett          #+#    #+#              #
#    Updated: 2020/10/06 17:22:42 by lmittie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_SRC =	srcs

DIR_INC =	includes

DIR_LIB =	libft

LIBNAME =	$(DIR_LIB)/libft.a

FLAGS =		-Wall -Wextra -Werror -O2

NAME = 		lem-in

SOURCES =	$(DIR_SRC)/adjacency_matrix.c \
			$(DIR_SRC)/checkers.c \
			$(DIR_SRC)/deleting.c \
			$(DIR_SRC)/main.c \
			$(DIR_SRC)/parse_ants_number.c \
			$(DIR_SRC)/parse_links.c \
			$(DIR_SRC)/parse_map.c \
			$(DIR_SRC)/parse_rooms.c \
			$(DIR_SRC)/return_room.c \
			$(DIR_SRC)/dinic_algorithm.c \
			$(DIR_SRC)/print_ants.c \
			$(DIR_SRC)/count_ants_on_each_path.c \
			$(DIR_SRC)/add_path.c \
			$(DIR_SRC)/finding_best_path.c \
			$(DIR_SRC)/init.c \
			$(DIR_SRC)/hasher.c \
			$(DIR_SRC)/error.c \
			$(DIR_SRC)/insert_room.c \
			$(DIR_SRC)/print_line.c

INCLUDES = 	$(DIR_INC)

OBJECTS =	$(patsubst %.c,%.o,$(SOURCES))

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(DIR_LIB)
	@gcc $(FLAGS) -o $(NAME) $(SOURCES) -I $(DIR_INC) -I $(DIR_LIB) $(LIBNAME)

%.o: %.c $(INCLUDES)
	@gcc $(FLAGS) -I $(DIR_INC) -I $(DIR_LIB) $< -c -o $@

clean:
	@rm -rf $(OBJECTS)
	@make -C $(DIR_LIB) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(DIR_LIB) fclean

re: fclean all
