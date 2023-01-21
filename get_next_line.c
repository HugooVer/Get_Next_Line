/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:38:55 by hvercell          #+#    #+#             */
/*   Updated: 2023/01/20 23:26:59 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	rest[BUFFER_SIZE + 1] = {0};
}












char	*get_next_line(int fd)
{
	ssize_t		new_line_index;
	static char	rest[BUFFER_SIZE + 1] = {0};

	rest = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (rest == NULL)
		return (NULL);
	new_line_index = ft_memchr_i(rest, '\n');
	if (new_line_index == -1)
		ft_add_read(rest, new_line_index, fd);
	else
		return (ft_return_line(rest, new_line_index));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ret;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len1 = 0;
	len2 = 0;
	if (s1 != NULL)
		len1 = ft_strlen(s1);
	if (s2 != NULL)
		len2 = ft_strlen(s2);
	ret = malloc((len1 + len2 + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_strlcpy(ret, s1, len1 + 1);
	if (s2 != NULL)
		ft_strlcpy(ret + len1, s2, len2 + 1);
	return (free(s1), free(s2), ret);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen (src));
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

int	main()
{
	int			fd;
	const char	file = "test_file";

	fd = open(file, O_RDONLY);
	printf(get_next_line(fd));
}