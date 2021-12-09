/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:16:56 by amyroshn          #+#    #+#             */
/*   Updated: 2021/12/09 12:39:44 by amyroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

t_flist	*get_flist(t_flist *f, int fd)
{
	while (f && fd != f->fd)
		f = f->next;
	return (f);
}

t_flist *add_list_element(t_flist *f, int fd)
{
	t_flist *element;

	element = (t_flist *) malloc(sizeof(t_flist));
	if (!element)
		return (NULL);
	element->fd = fd;
	element->buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(element);
		return (NULL);
	}
	element->buffer[0] = 0;
	element->next = NULL;
	if (f)
		f->next = element;
	return (element);
}

size_t	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_strncat(char	*dest, char	*src, unsigned int nb)
{
	unsigned int	dest_len;
	unsigned int	i;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i] && i < nb)
	{
		dest[dest_len] = src[i];
		i++;
		dest_len++;
	}
	dest[dest_len] = '\0';
	return (dest);
}
