/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:15:56 by amyroshn          #+#    #+#             */
/*   Updated: 2021/12/14 11:36:16 by amyroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_buffer(t_felement *elem, int nl_index)
{
	char	*tmp;

	if (ft_strlen(elem->buffer) == 0)
		return (NULL);
	if (nl_index >= 0)
	{
		tmp = ft_strdup(&elem->buffer[nl_index + 1]);
		elem->buffer[nl_index + 1] = 0;
		if (!tmp)
			return (NULL);
		elem->line = ft_strdup(elem->buffer);
		if (!elem->line)
			return (NULL);
		free(elem->buffer);
		elem->buffer = tmp;
	}
	else
	{
		elem->line = elem->buffer;
		elem->buffer = ft_strdup("");
		if (!elem->buffer)
			return (NULL);
	}
	return (elem->line);
}

char	*read_bfrsep(t_felement *elem)
{
	int	read_bytecount;
	char	*buf;
	int		nl_index;

	buf = (char *) malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (elem->line)
		elem->line = NULL;
	nl_index = get_nlpos(elem->buffer);
	while (nl_index < 0 && (read_bytecount
			= read(elem->fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_bytecount] = 0;
		elem->buffer = ft_strjoin(elem->buffer, buf, BUFFER_SIZE);
		if (!elem->buffer)
			return (NULL);
		nl_index = get_nlpos(elem->buffer);
	}
	free(buf);
	return (check_buffer(elem, nl_index));
}

char *get_next_line(int fd)
{
	static t_felement	*elem_arr[1025]; //FIXME CONST!!!!!!!

	if (fd < 0)
		return (NULL);
	if (!elem_arr[fd])
		elem_arr[fd]  = init_elem(fd);
	return (read_bfrsep(elem_arr[fd]));	
/*	if(!(current = get_flist(first, fd)))
		current = add_list_element(first, fd);
	return (read_bfrsep(current)); //FIXME existant fd
*/}
