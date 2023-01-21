/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:38:55 by hvercell          #+#    #+#             */
/*   Updated: 2023/01/21 21:13:02 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t		size;
	static char	rest[BUFFER_SIZE + 1] = {0};
	char		*buf;
	char		line;

	buf = NULL;
	if (ft_memchr_i(rest, '\n') != -1)
	{
		line = ft_strnjoin(line, rest, ft_memchr_i(rest, '\n'));
		rest = ft_strnjoin(rest, line + ft_memchr_i(rest, '\n'), ft_strlen(line + ft_memchr_i(rest, '\n')));
	}
	else
	{
		if (rest != NULL)
			line = ft_strnjoin(line, rest, ft_strlen(rest));
		size = read(fd, buf, BUFFER_SIZE);
		line = ft_strnjoin(line, buf, ft_strlen(buf));
		get_next_line(fd);
	}
}

int	main(int argc, char **argv)
{
	int	fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	printf("[%s]", get_next_line(fd));
	return (1);
}
