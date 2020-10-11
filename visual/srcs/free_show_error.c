/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_show_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:29:47 by acarlett          #+#    #+#             */
/*   Updated: 2020/10/06 14:28:12 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

void		handle_room_number(t_map_data *data)
{
	if (data->rooms_number > 250)
	{
		free_data(data);
		ft_putstr("\n\tToo much rooms, they don`t fit to the window"
		":c\n\tPlease, can you try to enter a smaller number of rooms?)\n\n");
		exit(0);
	}
}

void		free_show_error(t_map_data *data)
{
	free_data(data);
	ft_putstr("Exit Code: ");
	ft_putnbr(MALLOC_ERROR);
	write(1, "\n", 1);
	exit(MALLOC_ERROR);
}
