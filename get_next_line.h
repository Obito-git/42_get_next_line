/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:13:15 by amyroshn          #+#    #+#             */
/*   Updated: 2021/12/09 14:44:30 by amyroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GNL_H
# define GNL_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //FIXME

typedef struct s_flist
{
	int					fd;
	int				byte_read;
	char				*buffer;
	struct s_flist		*next;
}				t_flist;

int	find_char_index(char *str);//FIXME DELETE
void	print_list(); //FIXME
char *get_next_line(int fd);
char	*ft_strncat(char *dest, const char *src, unsigned int nb);
char	*ft_strdup(const char	*src);
size_t	ft_strlen(const char *str);
t_flist	*get_flist(t_flist *f, int fd);

# endif
