/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:46:46 by acarlett          #+#    #+#             */
/*   Updated: 2020/10/04 20:48:26 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

int			ft_abs(int first, int second)
{
	int answer;

	if (first >= second)
		answer = first - second;
	else
		answer = second - first;
	return (answer);
}

int			find_coord_by_name(t_map_data *data, int id, char c)
{
	t_room_list *room;

	room = data->rooms;
	while (room->room_data->id != id)
	{
		room = room->next;
	}
	return (c == 'x' ? room->room_data->coords.x : room->room_data->coords.y);
}

int			find_name(int **matrix, int *i, int *j, int count)
{
	int n;
	int m;

	n = (*i);
	m = (*j);
	while (n < count)
	{
		while (m < count)
		{
			if (matrix[n][m])
			{
				(*i) = n;
				(*j) = m;
				return (1);
			}
			m++;
		}
		n++;
		m = 0;
	}
	return (0);
}

void		draw_a_lot_lines(t_visual *vis)
{
	SDL_RenderDrawLine(vis->rend, vis->line.x1, vis->line.y1,
									vis->line.x2, vis->line.y2);
	SDL_RenderDrawLine(vis->rend, vis->line.x1, vis->line.y1 + 1,
									vis->line.x2, vis->line.y2 + 1);
	SDL_RenderDrawLine(vis->rend, vis->line.x1 + 1, vis->line.y1,
									vis->line.x2 + 1, vis->line.y2);
	SDL_RenderDrawLine(vis->rend, vis->line.x1, vis->line.y1 - 1,
									vis->line.x2, vis->line.y2 - 1);
	SDL_RenderDrawLine(vis->rend, vis->line.x1 - 1, vis->line.y1,
									vis->line.x2 - 1, vis->line.y2);
	SDL_RenderDrawLine(vis->rend, vis->line.x1, vis->line.y1 + 2,
									vis->line.x2, vis->line.y2 + 2);
	SDL_RenderDrawLine(vis->rend, vis->line.x1, vis->line.y1 - 2,
									vis->line.x2, vis->line.y2 - 2);
	if (ft_abs(vis->line.y1, vis->line.y2) > ft_abs(vis->line.x1,
														vis->line.x2))
	{
		SDL_RenderDrawLine(vis->rend, vis->line.x1 + 2, vis->line.y1,
										vis->line.x2 + 2, vis->line.y2);
	}
}

void		draw_links(t_visual *vis, t_map_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	SDL_SetRenderDrawColor(vis->rend, 100, 100, 100, 255);
	while (find_name(data->adjacency_matrix, &i, &j, data->rooms_number))
	{
		vis->line.x1 = find_coord_by_name(data, i, 'x');
		vis->line.y1 = find_coord_by_name(data, i, 'y');
		vis->line.x2 = find_coord_by_name(data, j, 'x');
		vis->line.y2 = find_coord_by_name(data, j, 'y');
		if (j == (data->rooms_number - 1))
		{
			i++;
			j = 0;
		}
		else
			j++;
		draw_a_lot_lines(vis);
	}
}
