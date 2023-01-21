/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:39:13 by hvercell          #+#    #+#             */
/*   Updated: 2023/01/20 21:41:43 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(const char *s, const size_t n)
{
	size_t	i;
	char	*ret;

	ret = malloc((n + 1) * sizeof(char));
	i = 0;
	if (ret == NULL)
		return (NULL);
	while (i <= n)
	{
		ret[i] = s[i];
		++i;
	}
	ret[i] = '\0';
	return (ret);
}

void	*ft_memchr_i(const void *s, int c)
{
	size_t			i;
	const size_t	n = ft_strlen(s);

	i = 0;
	c = (unsigned char) c;
	while (i < n)
	{
		if (*(const unsigned char *)(s + i) == c)
			return ((void *) i);
		++i;
	}
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		++len;
	return (len);
}

void	ft_add_read(char *rest, size_t new_line_index, int fd)
{
	size_t	size;
	char	*temp;
	char	*ret;

	size = read(fd, temp, BUFFER_SIZE);
	ret = ft_strjoin(rest, temp);
	free (rest);
	free (temp);
	return (ret);
}

void	ft_return_line(char *rest, size_t new_line_index)
{
	size_t	len;
	char	*temp;

	len = (size_t)ft_memchr_i(rest, '\n');
	temp = ft_strndup(rest, len);
	rest = ft_strndup(rest + len, ft_strlen(rest + len));
	return (temp);
}
