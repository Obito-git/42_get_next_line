/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:13:15 by amyroshn          #+#    #+#             */
/*   Updated: 2021/12/14 11:33:46 by amyroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GNL_H
# define GNL_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //FIXME

typedef struct s_felement
{
	int					fd;
	char				*line;
	char				*buffer;
}				t_felement;

void	print_list(); //FIXME
t_felement *init_elem(int fd);
char *get_next_line(int fd);
char	*ft_strjoin(char *from, char *to, size_t size);
int	get_nlpos(char *str);
char	*ft_strdup(const char	*src);
size_t	ft_strlen(const char *str);

# endif
