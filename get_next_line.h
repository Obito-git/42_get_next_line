/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:13:15 by amyroshn          #+#    #+#             */
/*   Updated: 2021/12/15 12:14:40 by amyroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MAX_FD 1024
# include <stdlib.h>
# include <unistd.h>

typedef struct s_felement
{
	int					fd;
	char				*line;
	char				*buffer;
}				t_felement;

t_felement	*init_elem(int fd);
char		*get_next_line(int fd);
char		*ft_strjoin(char *from, char *to, size_t size);
char		*free_memory(t_felement *elem, char *tmp);
char		*ft_strdup(const char	*src);
size_t		ft_strlen(const char *str);

#endif
