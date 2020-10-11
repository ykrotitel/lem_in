/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:41:07 by acarlett          #+#    #+#             */
/*   Updated: 2020/10/06 14:28:04 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "../SDL/include/SDL.h"
# include "../SDL/include/SDL_image.h"
# include <stdbool.h>
# include <time.h>
# include "../../libft/libft.h"

# define WIDTH	1700
# define HEIGHT	1200

typedef struct	s_max_coords
{
	int			max_x;
	int			min_x;
	int			max_y;
	int			min_y;
}				t_max_coords;

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
	INVALID_LINKS = 3,
	INIT_SDL_ERROR = 4,
	SIMILAR_COORDS = 5,
	CREATE_SURFACE = 6,
	CREATE_RENDER = 7,
	CREATE_TEXTURE = 8
}				t_error_code;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_room_data
{
	t_point		coords;
	int			id;
	t_room_type	type;
	char		*name;
}				t_room_data;

typedef struct	s_room_list
{
	t_room_data			*room_data;
	struct s_room_list	*next;
}				t_room_list;

typedef struct	s_map_data
{
	int				ants_num;
	int				rooms_number;
	char			**rooms_by_id;
	t_room_list		*rooms;
	t_max_coords	max_coords;
	int				**adjacency_matrix;
	int				id_start_room;
	int				start;
	int				end;
}				t_map_data;

typedef struct	s_window
{
	int			x;
	int			y;
}				t_window;

typedef struct	s_line
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
}				t_line;

typedef struct	s_paths
{
	int				*id_list;
	int				*id_list_root;
	int				ant_num;
	int				start;
	SDL_Surface		*surface;
	SDL_Rect		pos;
	SDL_Texture		*tex;
	struct s_paths	*next;
	struct s_paths	*prev;
	int				i;
}				t_paths;

typedef struct	s_visual
{
	t_window	size;
	t_line		line;
	t_paths		*paths;
	int			delta_x;
	int			delta_y;
	int			size_node;
	SDL_Window	*win;
	SDL_Renderer*rend;
	SDL_Event	event;
	SDL_Surface	*surface;
	SDL_Texture	*back;
	SDL_Texture	*logo_21;
	SDL_Rect	pos;
	Uint32		render_flags;
	int			delay;
	bool		loop;
	bool		run;
}				t_visual;

/*
** random.c
*/
int				random_number(int nbr_min, int nbr_max);
int				random_color();
void			draw_random_points(int nbr_points, bool randomize_color,
															SDL_Renderer *rend);

/*
** all parse
*/
int				parse_ants_number(void);
void			parse_links(t_map_data *data);
void			parse_map(t_map_data *data);
void			parse_rooms(t_map_data *data);
t_room_type		check_if_comment(char **line, t_map_data *data);
int				size_of_matrix_rows(char **matrix);
void			free_delete_exit(char **line, char **splitted_line,
												int exit_num, t_map_data *data);
int				return_room_index(char *room_name, t_room_list *list);
void			add_link(char *line, t_map_data *data);
void			push_back_room(t_room_list **list, t_room_data *room_data,
							t_map_data *data, char **line);
void			fill_adjacency_matrix(int index1, int index2,
							int ***adjacency_matrix, int size);
void			parse_path(t_map_data *data, t_visual *vis);

/*
**	work_with_coords.c
*/
void			new_coords(t_map_data *data, t_visual *vis);
void			check_coords(t_map_data *data, t_visual *vis);

/*
** min_max_coords.c
*/
void			init_coord(t_room_list *root, t_map_data *data);
void			find_min_max(t_room_list *room, t_map_data *data);

/*
** fill_delta.c
*/
void			new_coords(t_map_data *data, t_visual *vis);

/*
** render_load_surface.c
*/
void			render_surface(t_map_data *data, t_visual *vis);

/*
** background_graph.c
*/
void			background_graph(t_visual *vis, t_map_data *data);
void			destroy_all_quit(t_visual *vis);

/*
** all_draw
*/
void			draw_node(t_visual *vis, t_map_data *data);
void			draw_links(t_visual *vis, t_map_data *data);
void			just_draw_ant_on_graph(t_paths **paths,
										t_visual *vis, t_room_list *buff);
void			draw_ant_on_start(t_paths **paths, t_visual *vis,
									t_map_data *data, t_room_list *buff);
void			draw_ant_on_finish(t_paths **paths, t_visual *vis,
									t_map_data *data, t_room_list *buff);

/*
** delete
*/
void			free_paths(t_paths **paths);
void			free_data(t_map_data *data);

/*
** random.c
*/
void			handle_room_type(t_map_data *data, t_room_type room_type,
								char *line, int exit_code);
void			free_strdel_exit(int str_out, t_map_data *data,
										char *line, int exit_code);
void			get_error_free_data(t_map_data *data,
											int exit_code, char *str_out);
void			image_load(t_visual *vis, t_paths **parse,
										t_map_data *data, int i);
int				return_id_by_name(t_room_list *rooms, char *name_room);

/*
** free_show_error.c
*/
void			handle_room_number(t_map_data *data);
void			free_show_error(t_map_data *data);

#endif
