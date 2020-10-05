/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:45:04 by acarlett          #+#    #+#             */
/*   Updated: 2020/10/04 20:48:42 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

void		set_color(t_visual *vis, t_room_list *room)
{
	if (room->room_data->type == START)
		SDL_SetRenderDrawColor(vis->rend, 50, 180, 50, 255);
	else if (room->room_data->type == END)
		SDL_SetRenderDrawColor(vis->rend, 180, 50, 50, 255);
	else
		SDL_SetRenderDrawColor(vis->rend, 255, 255, 255, 255);
}

void		make_four_lines(t_visual *vis, t_room_list *room, int x, int y)
{
	SDL_RenderDrawLine(vis->rend, room->room_data->coords.x + x,
									room->room_data->coords.y + y,
									room->room_data->coords.x - x,
									room->room_data->coords.y + y);
	SDL_RenderDrawLine(vis->rend, room->room_data->coords.x + x,
									room->room_data->coords.y + y,
									room->room_data->coords.x + x,
									room->room_data->coords.y - y);
	SDL_RenderDrawLine(vis->rend, room->room_data->coords.x - x,
									room->room_data->coords.y - y,
									room->room_data->coords.x - x,
									room->room_data->coords.y + y);
	SDL_RenderDrawLine(vis->rend, room->room_data->coords.x - x,
									room->room_data->coords.y - y,
									room->room_data->coords.x + x,
									room->room_data->coords.y - y);
}

void		make_node(t_visual *vis, t_room_list *room, int y)
{
	int x;
	int delta;
	int error;

	x = 0;
	delta = 1 - 2 * y;
	while (y >= 0)
	{
		make_four_lines(vis, room, x, y);
		error = 2 * (delta + y) - 1;
		if ((delta < 0) && (error <= 0))
			delta += 2 * ++x + 1;
		else if ((delta > 0) && (error > 0))
			delta -= 2 * --y + 1;
		else
			delta += 2 * (++x - --y);
	}
}

void		draw_node(t_visual *vis, t_map_data *data)
{
	t_room_list *room;

	SDL_SetRenderDrawColor(vis->rend, 255, 255, 255, 255);
	room = data->rooms;
	if (data->rooms_number < 10)
		vis->size_node = 25;
	else if (data->rooms_number >= 10 && data->rooms_number < 20)
		vis->size_node = 20;
	else if (data->rooms_number >= 20 && data->rooms_number < 40)
		vis->size_node = 10;
	else
		vis->size_node = 7;
	while (room != NULL)
	{
		set_color(vis, room);
		make_node(vis, room, vis->size_node);
		room = room->next;
	}
}
