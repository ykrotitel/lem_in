/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_deleting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:54:10 by lmittie           #+#    #+#             */
/*   Updated: 2020/10/05 19:53:31 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

void		free_delete_exit(char **line, char **splitted_line,
											int exit_num, t_map_data *data)
{
	ft_strdel(line);
	ft_putstr("Exit Code: ");
	ft_putnbr(exit_num);
	write(1, "\n", 1);
	free_data(data);
	delete_splitted_line(&splitted_line);
	exit(exit_num);
}

void		free_matrix(int ***matrix, int size)
{
	int i;

	if (*matrix == NULL)
		return ;
	i = 0;
	while (i < size)
	{
		if ((*matrix)[i])
			free((*matrix)[i]);
		(*matrix)[i] = NULL;
		i++;
	}
	free(*matrix);
	*matrix = NULL;
}

void		free_rooms(t_room_list **room)
{
	t_room_list	*tmp;
	char		*line;

	while ((*room) != NULL)
	{
		tmp = (*room);
		line = tmp->room_data->name;
		ft_strdel(&line);
		tmp->next = NULL;
		free(tmp);
		(*room) = (*room)->next;
	}
}

void		free_paths(t_paths **paths)
{
	t_paths *tmp;

	while ((*paths)->prev != NULL)
	{
		if ((*paths) != NULL)
			(*paths)->id_list = (*paths)->id_list_root;
		(*paths) = (*paths)->prev;
	}
	while ((*paths) != NULL)
	{
		tmp = (*paths);
		(*paths) = (*paths)->next;
		free(tmp->id_list_root);
		SDL_DestroyTexture(tmp->tex);
		tmp->prev = NULL;
		tmp->next = NULL;
		free(tmp);
	}
}

void		free_data(t_map_data *data)
{
	int i;

	if (data->rooms_by_id)
	{
		i = 0;
		while (i < data->rooms_number)
		{
			if (data->rooms_by_id[i])
				ft_strdel(&data->rooms_by_id[i]);
			i++;
		}
		free(data->rooms_by_id);
	}
	free_rooms(&data->rooms);
	free_matrix(&(data->adjacency_matrix), data->rooms_number);
}
