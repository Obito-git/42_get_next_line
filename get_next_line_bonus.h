/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:14:46 by amyroshn          #+#    #+#             */
/*   Updated: 2021/12/15 14:15:00 by amyroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define MAX_FD 1024
# include <stdlib.h>
# include <unistd.h>

typedef struct s_felement
{
	int					fd;
	int					is_read;
	char				*line;
	char				*buffer;
	char				*buf_temp;
}				t_felement;

t_felement	*init_elem(int fd);
char		*get_next_line(int fd);
char		*ft_strjoin(char *from, char *to, size_t size);
char		*free_memory(t_felement *elem, char *tmp);
char		*ft_strdup(const char	*src);
size_t		ft_strlen(const char *str);

#endif
