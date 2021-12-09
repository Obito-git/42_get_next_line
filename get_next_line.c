/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:15:56 by amyroshn          #+#    #+#             */
/*   Updated: 2021/12/09 15:03:40 by amyroshn         ###   ########.fr       */
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



/*
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
} */

char	*expand_buffer(t_flist *elem, char *buf, int bytes)
{
	char	*temp;
	char	*res;
	size_t	i;
	
	i = 0;
	temp = (char *) malloc(ft_strlen(elem->buffer) + bytes + 1);
	if (!temp)
		return (NULL);
	res = NULL;
	temp[0] = 0;
	ft_strncat(temp, elem->buffer, ft_strlen(elem->buffer));
	ft_strncat(temp, buf, bytes);
	free(elem->buffer);
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
	{
		elem->buffer = ft_strdup(&temp[i + 1]);
		temp[i + 1] = 0;
		res = ft_strdup(temp);
		free(temp);
	}
	else
		elem->buffer = temp;
	return (res);
}

char *read_bfrsep(t_flist *elem)
{
	int	read_bytecount;
	char	*buf;
	char	*res;

	buf = (char *) malloc(BUFFER_SIZE + 1);
	read_bytecount = 0;
	if (!buf)
		return (NULL);
	while ((read_bytecount = read(elem->fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_bytecount] = 0;
		res = expand_buffer(elem, buf, read_bytecount);
		if (res)
		{
			free(buf);
			return (res);
		}
	}
	free(buf);
	return (NULL);
}

char *get_next_line(int fd)
{
	static t_flist	*first; //FIXME move to gnl func
	t_flist			*current;

	if (fd < 0)
		return (NULL);
	if (!first)
		first = add_list_element(NULL, fd);
	if(!(current = get_flist(first, fd)))
		current = add_list_element(first, fd);
	return (read_bfrsep(current)); //FIXME existant fd
}
