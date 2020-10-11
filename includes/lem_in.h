/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 17:31:33 by lmittie           #+#    #+#             */
/*   Updated: 2020/10/05 16:53:20 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

# define INF				1000000000
# define HASH_TABLE_SIZE	500

typedef enum	e_room_type
{
	START,
	END,
	DEFAULT,
	PARSE_ERROR
}				t_room_type;

typedef enum	e_exit_code
{
	MALLOC_ERROR = 10,
	INVALID_ANTS = 1,
	INVALID_ROOMS = 2,
	INVALID_LINKS = 3
}				t_exit_code;

typedef struct	s_room_data
{
	size_t		input_id;
	size_t		output_id;
	size_t		id;
	t_room_type	type;
	char		*name;
}				t_room_data;

typedef struct	s_path
{
	int				id;
	struct s_path	*next;
}				t_path;

typedef struct	s_paths
{
	t_path			*id_list;
	int				path_len;
	int				ants_num;
	int				*ants_by_id;
	int				last_ant_id;
	int				output_lines;
	struct s_paths	*next;
	struct s_paths	*prev;
}				t_paths;

typedef struct	s_dinic_data
{
	int				*ptr;
	int				*distance;
	int				*queue;
	int				start;
	int				end;
	int				n;
}				t_dinic_data;

typedef struct	s_node
{
	t_room_data		*room;
	struct s_node	*next;
}				t_node;

typedef struct	s_edge
{
	int		a;
	int		b;
	int		cap;
	int		flow;
}				t_edge;

typedef struct	s_data
{
	int				ants_num;
	int				id_counter;
	int				rooms_number;
	char			**rooms_by_id;
	int				*direction_id;
	t_node			*hash_table[HASH_TABLE_SIZE];
	t_paths			*paths;
	t_edge			**edges;
	int				*last_edge_id;
	int				start;
	int				end;
}				t_data;

/*
 ** print_line.c
*/
void			print_map_line(const char *line);
void			print_error_message(void);

/*
 ** insert_room.c
*/
int				insert_room(t_node *(*hash_table)[HASH_TABLE_SIZE],
							t_room_data *room_data,
							int *id_counter);
/*
 ** hasher.c
*/
int				hasher(const char *name);

/*
 ** init.c
*/
void			init_structure(t_data *data);

/*
 ** finding_best_path.c
*/
void			find_best_path(t_paths **best_paths, t_data *data);

/*
 ** add_path.c
*/
void			add_path(t_paths **paths, t_path **path, int path_length);

/*
 ** print_ants.c
*/
void			print_ants(t_data *data);

/*
 ** count_ants_on_each_path.c
*/
int				count_ants_on_each_path(t_paths **paths, int ants_num);

/*
 ** dinic_algorithm.c
*/
t_paths			*dinic(t_data *data);

/*
 ** parse_map.c
*/
void			parse_map(t_data *data);

/*
 ** parse_ants_number.c
*/
int				parse_ants_number(void);

/*
 ** parse_links.c
*/
void			add_link(char *line, t_data *data);
void			parse_links(t_data *data);

/*
 ** checkers.c
*/
t_room_type		check_if_comment(char **line, t_data *data);
int				size_of_matrix_rows(char **matrix);

/*
 ** parse_rooms.c
*/
t_room_data		*create_room(char **line, t_room_type room_type, t_data *data);
void			parse_rooms(t_data *data);

/*
 ** adjacency_matrix.c
*/
int				fill_edge_matrix(t_room_data *room1,
						t_room_data *room2,
						t_data *data,
						int size);

/*
 ** error.c
*/
t_exit_code		free_line_and_splitted_exit(char **line,
											char ***splitted_line,
											t_data *data,
											t_exit_code exit_code);
t_exit_code		free_line_exit(char **line,
							t_data *data,
							t_exit_code exit_code);
t_exit_code		free_data_exit(t_data *data, t_exit_code exit_code);
t_exit_code		no_free_exit(t_exit_code exit_code);

/*
 ** deleting.c
*/
void			free_data(t_data *data);
void			free_paths(t_paths **paths);
void			free_matrix(t_edge ***matrix, int size);
void			free_path(t_path **path);

/*
 ** return_room.c
*/
t_room_data		*return_room(char *room_name,
							t_node *hash_table[HASH_TABLE_SIZE]);

#endif
