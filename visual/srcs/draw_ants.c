/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:47:02 by acarlett          #+#    #+#             */
/*   Updated: 2020/10/04 20:41:43 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

void		draw_ant_on_start(t_paths **paths, t_visual *vis,
								t_map_data *data, t_room_list *buff)
{
	(*paths)->start = 0;
	while (buff->room_data->type != START)
		buff = buff->next;
	vis->pos.w = vis->size_node * 5;
	vis->pos.h = vis->size_node * 4;
	vis->pos.x = (buff->room_data->coords.x - (vis->size_node * 2));
	vis->pos.y = (buff->room_data->coords.y - (vis->size_node * 2));
	SDL_Delay(80);
	SDL_RenderCopy(vis->rend, (*paths)->tex, NULL, &(vis->pos));
	buff = data->rooms;
	(*paths) = (*paths)->prev;
}

void		draw_ant_on_finish(t_paths **paths, t_visual *vis,
								t_map_data *data, t_room_list *buff)
{
	while (buff->room_data->type != END)
		buff = buff->next;
	vis->pos.w = vis->size_node * 5;
	vis->pos.h = vis->size_node * 4;
	vis->pos.x = (buff->room_data->coords.x - (vis->size_node * 2));
	vis->pos.y = (buff->room_data->coords.y - (vis->size_node * 2));
	SDL_Delay(80);
	SDL_RenderCopy(vis->rend, (*paths)->tex, NULL, &(vis->pos));
	buff = data->rooms;
	(*paths) = (*paths)->prev;
}

void		just_draw_ant_on_graph(t_paths **paths,
					t_visual *vis, t_room_list *buff)
{
	vis->pos.w = vis->size_node * 5;
	vis->pos.h = vis->size_node * 4;
	vis->pos.x = (buff->room_data->coords.x - (vis->size_node * 2));
	vis->pos.y = (buff->room_data->coords.y - (vis->size_node * 2));
	SDL_Delay(80);
	SDL_RenderCopy(vis->rend, (*paths)->tex, NULL, &(vis->pos));
}
