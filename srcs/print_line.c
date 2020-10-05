/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 19:52:38 by lmittie           #+#    #+#             */
/*   Updated: 2020/10/01 19:54:16 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_error_message(void)
{
	write(2, "ERROR\n", 6);
}

void	print_map_line(const char *line)
{
	ft_putstr(line);
	ft_putchar('\n');
}
