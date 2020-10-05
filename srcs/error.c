/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 17:45:06 by lmittie           #+#    #+#             */
/*   Updated: 2020/10/01 17:52:45 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_exit_code	free_line_and_splitted_exit(char **line,
										char ***splitted_line,
										t_data *data,
										t_exit_code exit_code)
{
	ft_strdel(line);
	delete_splitted_line(splitted_line);
	free_data(data);
	print_error_message();
	return (exit_code);
}

t_exit_code	free_line_exit(char **line, t_data *data, t_exit_code exit_code)
{
	ft_strdel(line);
	free_data(data);
	print_error_message();
	return (exit_code);
}

t_exit_code	free_data_exit(t_data *data, t_exit_code exit_code)
{
	free_data(data);
	if (exit_code != 0)
		print_error_message();
	return (exit_code);
}

t_exit_code	no_free_exit(t_exit_code exit_code)
{
	print_error_message();
	return (exit_code);
}
