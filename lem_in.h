/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 19:11:09 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/04 19:17:51 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
​
# include "libft/libft.h"
# include <unistd.h>
# include <libc.h>
​
# define CAPACITY 13
;
typedef struct	s_point
{
	int 		x;
	int 		y;
}				t_point;

typedef struct			s_room_data
{
	struct s_point		*coords;
	char 				*name;
	struct s_room_data	**next_room;
}						t_room_data;
​
typedef struct			s_deque
{
	struct s_room_data	**rooms_data;
	size_t 				size;
	struct s_deque		*next_block;
}						t_deque;
​
typedef struct		s_data
{
	int32_t			ants_num;
	struct s_deque	*rooms;
}					t_data;
​
# endif