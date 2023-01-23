/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:38:55 by hvercell          #+#    #+#             */
/*   Updated: 2023/01/23 22:41:11 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		size;
	ssize_t		rest_s;
	ssize_t		buf_s;
	static char	rest[BUFFER_SIZE + 1] = {0};
	char		buf[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	rest_s = ft_memchr_i(rest, '\n');
	if (rest_s != -1)
	{
		line = ft_strnjoin(line, rest, rest_s + 1);
		ft_strlcpy(rest, rest + rest_s + 1, ft_strlen(rest + rest_s) + 1);
	}
	else
	{
		while (ft_memchr_i(line, '\n') == -1)
		{
			line = ft_strnjoin(line, rest, ft_strlen(rest) + 1);
			ft_memset(rest, '\0', BUFFER_SIZE + 1);
			ft_memset(buf, '\0', BUFFER_SIZE + 1);
			size = read(fd, buf, BUFFER_SIZE);
			if (size == -1)
				return (free(line), NULL);
			if (size == 0 && line[0] != '\0')
				return (line);
			else if (size == 0)
				return (free(line), NULL);
			buf[size] = '\0';
			if (ft_memchr_i(buf, '\n') == -1)
			{
				line = ft_strnjoin(line, buf, ft_strlen(buf) + 1);
				ft_memset(buf, '\0', BUFFER_SIZE + 1);
			}
			else
			{
				buf_s = ft_memchr_i(buf, '\n');
				line = ft_strnjoin(line, buf, buf_s + 1);
				ft_memset(rest, '\0', BUFFER_SIZE + 1);
				ft_strlcpy(rest, buf + buf_s + 1, ft_strlen(buf + buf_s) + 1);
			}
		}
	}
	return (line);
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*res;
// 	int		i;

// 	(void)argc;
// 	i = 0;
// 	fd = open(argv[1], O_RDONLY);
// 	res = NULL;
// 	while (res != NULL || i == 0)
// 	{
// 		res = get_next_line(fd);
// 		printf("[%s]", res);
// 		free(res);
// 		++i;
// 	}
// 	return (1);
// }

//For bonus
//	static char	rest[fd][BUFFER_SIZE + 1] = {0};
// FOPEN_MAX