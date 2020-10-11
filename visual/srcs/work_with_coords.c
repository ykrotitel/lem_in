/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_coords.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 15:24:56 by acarlett          #+#    #+#             */
/*   Updated: 2020/10/06 14:17:32 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

int			compare_coord(t_room_list *root, t_room_list *cur)
{
	t_point first;
	t_point	second;

	first = root->room_data->coords;
	second = cur->room_data->coords;
	if ((first.x == second.x) && (first.y == second.y))
		return (1);
	return (0);
}

void		check_coords(t_map_data *data, t_visual *vis)
{
	t_room_list *root;
	t_room_list *cur;

	root = data->rooms;
	cur = root->next;
	init_coord(root, data);
	while (root->next != NULL)
	{
		while (cur != NULL)
		{
			if (compare_coord(root, cur))
			{
				write(1, "SIMILAR COORDS\n", 15);
				exit(SIMILAR_COORDS);
			}
			cur = cur->next;
		}
		root = root->next;
		find_min_max(root, data);
		cur = root->next;
	}
	new_coords(data, vis);
}

void		always_positive_dalta(t_visual *vis)
{
	if (!vis->delta_x)
		vis->delta_x = 1;
	if (!vis->delta_y)
		vis->delta_y = 1;
}

void		new_coords(t_map_data *data, t_visual *vis)
{
	t_room_list	*room;
	int			for_x;
	int			for_y;

	if (!(for_x = data->max_coords.max_x - data->max_coords.min_x))
		for_x = 1;
	if (!(for_y = data->max_coords.max_y - data->max_coords.min_y))
		for_y = 1;
	room = data->rooms;
	vis->delta_x = (WIDTH - 400) / for_x;
	vis->delta_y = (HEIGHT - 400) / for_y;
	always_positive_dalta(vis);
	while (room != NULL)
	{
		room->room_data->coords.x -= data->max_coords.min_x;
		room->room_data->coords.x *= vis->delta_x;
		room->room_data->coords.x += 200;
		room->room_data->coords.y -= data->max_coords.min_y;
		room->room_data->coords.y *= vis->delta_y;
		room->room_data->coords.y += 200;
		room = room->next;
	}
}
