/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:38:55 by hvercell          #+#    #+#             */
/*   Updated: 2023/01/16 18:34:15 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{	

	static char		*rest;

	rest = malloc(sizeof(char) * BUFFER_SIZE + 1);
		
}

void	printline(int fd, size_t size, char *buf)
{
	size_t		len;
	char		*t;
	static char	*rest;

	size = read(fd, buf, BUFFER_SIZE);
	len = (size_t)ft_memchr_i(buf, '\n', size);
	temp = ft_strndup(buf, len);
	rest = ft_strndup(buf + len + 1, size - len);
	printf("line : [%s]\nrest : [%s]\nall : [%s]\n", t, rest, buf);
	free(t);
}
