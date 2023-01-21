#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		++len;
	return (len);
}

ssize_t	ft_memchr_i(char *s, int c)
{
	size_t			i;
	const size_t	n = ft_strlen(s);

	i = 0;
	c = (unsigned char) c;
	while (i < n)
	{
		if (*(const unsigned char *)(s + i) == c)
			return (i);
		++i;
	}
	return (-1);
}
