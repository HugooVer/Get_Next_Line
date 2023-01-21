/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:38:55 by hvercell          #+#    #+#             */
/*   Updated: 2023/01/21 18:51:29 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t		size;
	static char	rest[BUFFER_SIZE + 1] = {0};
	char		*buf;
//	char		line;

	buf = NULL;
	if (ft_memchr_i(rest, '\n') != -1)
	{
		return (rest);
	}
	else
	{
		size = read(fd, buf, BUFFER_SIZE);
		return (buf);
	}
}



int	main(int argc, char **argv)
{
	int			fd;
	//const char	*file = "test_file7";

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	printf("[%s]", get_next_line(fd));
	return (1);
}
