/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:39:04 by hvercell          #+#    #+#             */
/*   Updated: 2023/01/24 22:09:21 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 24
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

char	*get_next_line(int fd);
void	ft_extract_line_from_rest(char **line, char *rest, ssize_t rest_s);
char	*ft_handle_end_of_file(ssize_t size, char **line);
void	ft_append_buf_to_line(char *buf, char **line, char *rest);

char	*ft_strnjoin(char *s1, char *s2, size_t n);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
ssize_t	ft_memchr_i(char *s, int c);
size_t	ft_strlen(char *s);
void	*ft_memset(void *s, int c, size_t n);

#endif
