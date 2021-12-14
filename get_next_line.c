/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:15:56 by amyroshn          #+#    #+#             */
/*   Updated: 2021/12/14 10:38:16 by amyroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
void	expand_buffer(t_felement *elem, char *buf)
{
	//FIX MALLOC PROTECTION
	size_t	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
	{
		elem->line = ft_strjoin(elem->buffer, buf, i + 1);
		elem->buffer = ft_strdup(&buf[i + 1]);
	}
	else
		elem->buffer = ft_strjoin(elem->buffer, buf, ft_strlen(buf));
}

char	*read_bfrsep(t_felement *elem)
{
	int	read_bytecount;
	char	*buf;

	buf = (char *) malloc(BUFFER_SIZE + 1);
	if (elem->line)
	{
	//	free(elem->line); //POTENTIAL ERROR, DOUBLE FREE
		elem->line = NULL;
	}
	if (!buf)
		return (NULL);
	while ((read_bytecount = read(elem->fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_bytecount] = 0;
		expand_buffer(elem, buf);
		if (elem->line)
		{
			free(buf);
			return (elem->line);
		}
	}
	free(buf);
	if (ft_strlen(elem->buffer) > 0)
	{
		elem->line = elem->buffer;
		elem->buffer = ft_strdup(""); //protection!!
		return (elem->line);
	}
	return (NULL);
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
