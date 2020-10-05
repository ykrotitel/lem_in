/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_coords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:11:40 by acarlett          #+#    #+#             */
/*   Updated: 2020/10/04 20:32:55 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

void		init_coord(t_room_list *room, t_map_data *data)
{
	data->max_coords.max_x = room->room_data->coords.x;
	data->max_coords.min_x = room->room_data->coords.x;
	data->max_coords.max_y = room->room_data->coords.y;
	data->max_coords.min_y = room->room_data->coords.y;
}

void		find_min_max(t_room_list *room, t_map_data *data)
{
	if (room->room_data->coords.x > data->max_coords.max_x)
	{
		data->max_coords.max_x = room->room_data->coords.x;
	}
	else if (room->room_data->coords.x < data->max_coords.min_x)
	{
		data->max_coords.min_x = room->room_data->coords.x;
	}
	if (room->room_data->coords.y > data->max_coords.max_y)
	{
		data->max_coords.max_y = room->room_data->coords.y;
	}
	else if (room->room_data->coords.y < data->max_coords.min_y)
	{
		data->max_coords.min_y = room->room_data->coords.y;
	}
}
