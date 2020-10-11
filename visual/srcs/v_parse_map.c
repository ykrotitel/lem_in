/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_parse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 17:58:16 by lmittie           #+#    #+#             */
/*   Updated: 2020/10/05 18:00:56 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

void	fill_rooms_by_id(char ***rooms, t_room_list *room_list, int n)
{
	int				i;
	t_room_list		*list_iter;

	if (!(*rooms = malloc(sizeof(char*) * n)))
		exit(MALLOC_ERROR);
	i = -1;
	list_iter = room_list;
	while (++i < n)
	{
		if (!((*rooms)[i] = ft_strdup(list_iter->room_data->name)))
			exit(MALLOC_ERROR);
		list_iter = list_iter->next;
	}
}

void	parse_map(t_map_data *data)
{
	data->ants_num = parse_ants_number();
	parse_rooms(data);
	fill_rooms_by_id(&data->rooms_by_id, data->rooms, data->rooms_number);
	if (data->start == -1 || data->end == -1)
		exit(INVALID_ROOMS);
	parse_links(data);
}
