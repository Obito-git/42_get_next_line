/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:16:56 by amyroshn          #+#    #+#             */
/*   Updated: 2021/12/07 18:51:25 by amyroshn         ###   ########.fr       */
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
	element->byte_read = 0;
	element->buffer = NULL;
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

char	*ft_strdup(const char	*src)
{
	char	*dest;

	if (!src)
		return (NULL);
	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[0] = 0;
	ft_strlcat(dest, src, ft_strlen(src) + 1);
	return (dest);
}

size_t	ft_strlcat(char	*dest, const char *src, size_t	size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
//	if (dest_len >= size || size == 0)
//		return (size + src_len);
	while (i  < size - 1 && src[i])
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[i + dest_len] = '\0';
	return (src_len + dest_len);
}
