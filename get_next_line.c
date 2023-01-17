/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:38:55 by hvercell          #+#    #+#             */
/*   Updated: 2023/01/17 18:15:46 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t		new_line_index;
	static char	*rest;

	rest = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (rest == NULL)
		return (NULL);
	new_line_index = ft_memchr_i(rest, '\n');
	if (new_line_index == NULL)
		ft_add_read(rest, new_line_index, fd);
	else
		ft_return_line(rest, new_line_index);
}






void	printline(int fd, size_t size, char *buf)
{
	size_t		len;
	char		*temp;
	static char	rest;

	size = read(fd, buf, BUFFER_SIZE);
	len = (size_t)ft_memchr_i(buf, '\n');
	temp = ft_strndup(buf, len);
	rest = ft_strndup(buf + len + 1, size - len);
	printf("line : [%s]\nrest : [%s]\nall : [%s]\n", temp, rest, buf);
	free(temp);
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
	return (ret);
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