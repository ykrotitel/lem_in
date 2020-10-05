/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:26:05 by lmittie           #+#    #+#             */
/*   Updated: 2020/09/17 18:56:15 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_lst	*crt_lst(int fd)
{
	t_lst	*new_lst;

	if (!(new_lst = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	new_lst->fd = fd;
	new_lst->cont = NULL;
	new_lst->next = NULL;
	return (new_lst);
}

t_lst	*find_lst(t_lst **b_lst, int fd)
{
	t_lst	*lst;
	t_lst	*tmp_lst;

	if (!*b_lst)
		return (*b_lst = crt_lst(fd));
	lst = *b_lst;
	while (lst && lst->fd != fd)
	{
		tmp_lst = lst;
		lst = lst->next;
	}
	if (!lst)
	{
		lst = crt_lst(fd);
		tmp_lst->next = lst;
	}
	return (lst);
}

int		ret_line(int size, char **cont, char **line)
{
	char	*tmp_str;

	tmp_str = *cont;
	if (!(*line = ft_strsub(tmp_str, 0, size)))
		return (-1);
	if (!(*cont = ft_strsub(tmp_str, size + 1, ft_strlen(tmp_str) - size - 1)))
	{
		ft_strdel(&tmp_str);
		return (-1);
	}
	if (!*cont[0])
	{
		free(*cont);
		*cont = NULL;
	}
	ft_strdel(&tmp_str);
	return (1);
}

int		ret_all_cont(char **line, char **cont)
{
	*line = *cont;
	*cont = NULL;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_lst	*b_lst;
	char			buff[BUFF_SIZE + 1];
	t_lst			*lst;
	char			*buff_n;
	int				nread;

	if (read(fd, buff, 0) < 0 || !(lst = find_lst(&b_lst, fd)) || line == NULL)
		return (-1);
	*line = NULL;
	while ((nread = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[nread] = '\0';
		if (!(lst->cont = ft_strjoin_free(lst->cont, buff, 1, 0)))
			return (-1);
		if (lst->cont && (buff_n = ft_strchr(lst->cont, '\n')))
			return (ret_line(buff_n - lst->cont, &lst->cont, line));
	}
	if (lst->cont && (buff_n = ft_strchr(lst->cont, '\n')))
		return (ret_line(buff_n - lst->cont, &lst->cont, line));
	if (lst->cont)
		return (ret_all_cont(line, &lst->cont));
	return (0);
}
