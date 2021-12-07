/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:15:56 by amyroshn          #+#    #+#             */
/*   Updated: 2021/12/07 18:54:59 by amyroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
	read();
	if (read char len == 1 && != \n)
		read()
	if (read char len > 1)
		check string while != \n || != EOF
		if (!\n && != EOF)
			save string
		if (\n)
			save after \n and check before
			save fd
			return before \n
		if (EOF)
			check before and return before EOF
			clear memory
*/


static t_flist	*first; //FIXME move to gnl func

void	print_list() //FIXME delete
{
	t_flist *f = first;
	printf("\n");
	while (f)
	{
		int width1 = printf("fd = %d\n", f->fd);
		int width2 = printf("br = %d\n", f->byte_read);
		width1 = width1 > width2 ? width1 : width2;
		for (int i = 0; i < width1; i++)
			printf("-");
		printf("\n");
		f = f->next;
	}
}


int	find_char_index(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char *read_bfrsep(t_flist *elem)
{
	int	read_bytecount;
	char	*buf;
	char	*temp;

	buf = (char *) malloc(BUFFER_SIZE + 1);
	read_bytecount = 0;
	if (!buf)
		return (NULL);
	while ((read_bytecount = read(elem->fd, buf, BUFFER_SIZE)) > 0)
	{
		elem->byte_read += read_bytecount;
		if (read_bytecount < BUFFER_SIZE)
		{
			if (!elem->buffer)
			{
				temp = ft_strdup(buf);
				free(buf);
				return (temp);
			}
			temp = (char *) malloc(ft_strlen(elem->buffer) + read_bytecount
									+ 1);
			if (!temp)
				return (NULL);
			temp[0] = 0;
			ft_strlcat(temp, elem->buffer, ft_strlen(elem->buffer));
			ft_strlcat(temp, buf, read_bytecount);
			free(elem->buffer);
			elem->buffer = NULL;
			free(buf);
			return (temp);
		}
		if (find_char_index(buf) != -1)
		{
			if (!elem->buffer)
			{
				temp = (char *) malloc(find_char_index(buf) + 1 + 1);
				if (!temp)
					return (NULL);
				temp[0] = 0;
				ft_strlcat(temp, buf, find_char_index(buf) + 1 + 1);
			}
			else
			{
				temp = (char *) malloc(ft_strlen(elem->buffer)
						+ find_char_index(buf) + 1 + 1);
				if (!temp)
					return (NULL);
				temp[0] = 0;
				ft_strlcat(temp, elem->buffer, ft_strlen(elem->buffer) + 1);
				ft_strlcat(temp, buf, find_char_index(buf) + 1 + 1);
				free(elem->buffer);
				elem->buffer = ft_strdup(&buf[find_char_index(buf) + 1]);
			}
				if (find_char_index(buf) + 1 != ft_strlen(buf))
					elem->buffer = ft_strdup(&buf[find_char_index(buf) + 1]);
				free(buf);
				return (temp);
		}
		if (!elem->buffer)
		{
			elem->buffer = (char *) malloc(BUFFER_SIZE + 1);
			elem->buffer[0] = 0;
			ft_strlcat(elem->buffer, buf, BUFFER_SIZE + 1);
		} 
		else
		{
			temp = (char *) malloc(ft_strlen(elem->buffer) +
					BUFFER_SIZE + 1);
			temp[0] = 0;
			ft_strlcat(temp, elem->buffer, ft_strlen(elem->buffer) + 1);
			free(elem->buffer);
			ft_strlcat(temp, buf, BUFFER_SIZE + 1);
			elem->buffer = temp;
		}
	}
	return (NULL);
}

char *get_next_line(int fd)
{
	//FIXME FIRST
	t_flist			*current;

	if (fd < 0)
		return (NULL);
	if (!first)
		first = add_list_element(NULL, fd);
	if(!(current = get_flist(first, fd)))
		current = add_list_element(first, fd);
	return (read_bfrsep(current)); //FIXME existant fd
}
