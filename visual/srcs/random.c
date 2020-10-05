/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:59:03 by acarlett          #+#    #+#             */
/*   Updated: 2020/10/05 14:04:53 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

void		handle_room_type(t_map_data *data, t_room_type room_type,
char *line, int exit_code)
{
	if (room_type == PARSE_ERROR)
		free_strdel_exit(1, data, line, INVALID_ROOMS);
	if (room_type == START)
		data->start = data->rooms_number;
	if (room_type == END)
		data->end = data->rooms_number;
}

void		free_strdel_exit(int str_out, t_map_data *data,
char *line, int exit_code)
{
	if (str_out == 1)
		ft_putstr("Empty line\n");
	if (str_out == 2)
		ft_putstr("too much start- or end- rooms\n");
	if (str_out == 3)
		ft_putstr("Parse Error\n");
	free_data(data);
	ft_strdel(&line);
	exit(exit_code);
}

void		get_error_free_data(t_map_data *data, int exit_code, char *str_out)
{
	ft_putstr(str_out);
	ft_putstr(SDL_GetError());
	write(1, "\n", 1);
	free_data(data);
	exit(exit_code);
}

int			return_id_by_name(t_room_list *rooms, char *name_room)
{
	t_room_list *cur;

	cur = rooms;
	while (ft_strcmp(cur->room_data->name, name_room))
		cur = cur->next;
	return (cur->room_data->id);
}

void		image_load(t_visual *vis, t_paths **parse, t_map_data *data, int i)
{
	char	*line;
	int		tmp;
	char	a[6];

	tmp = i % 10;
	if (!tmp)
		tmp = 1;
	a[0] = tmp + 48;
	a[1] = '.';
	a[2] = 'p';
	a[3] = 'n';
	a[4] = 'g';
	a[5] = '\0';
	line = ft_strjoin("images/ant\0", a);
	if (((*parse)->surface = IMG_Load(line)) == NULL)
		get_error_free_data(data, CREATE_SURFACE, "SDL_CreateSurface error: ");
	if (((*parse)->tex = SDL_CreateTextureFromSurface(vis->rend,
											(*parse)->surface)) == NULL)
		get_error_free_data(data, CREATE_TEXTURE, "SDL_CreateTexture error: ");
	ft_strdel(&line);
	SDL_FreeSurface((*parse)->surface);
}
