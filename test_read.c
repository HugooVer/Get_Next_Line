
#include "get_next_line.h"
/*
void	*ft_memchr_i(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	c = (unsigned char) c;
	while (i < n)
	{
		if (*(const unsigned char *)(s + i) == c)
		{
			return ((void *) i);
		}
		++i;
	}
	return (NULL);
}

char	*ft_strndup(const char *s, const size_t len)
{
	char			*ret;
	size_t			i;

	ret = malloc((len + 1) * sizeof(char));
	i = 0;
	if (ret == NULL)
		return (NULL);
	while (i <= len)
	{
		ret[i] = s[i];
		++i;
	}
	ret[i] = '\0';
	return (ret);
}

void	printlines(int fd, size_t size, char *buf)
{
	while(size == BUFFER_SIZE)
	{
		size = read(fd, buf, BUFFER_SIZE);
		buf[size] = '\0';
		write(1, buf, size);
	}
}

void	printline(int fd, size_t size)
{
	size_t		len;
	char		*temp;
	static char	*rest;
	char		*buf;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	size = read(fd, buf, BUFFER_SIZE);
	len = (size_t)ft_memchr_i(buf, '\n', size);
	temp = ft_strndup(buf, len);
	rest = ft_strndup(buf + len + 1, size - len);
	printf("line : [%s]\nrest : [%s]\nall : [%s]\n", temp, rest, buf);
	free(temp);
	free(buf);
}
*/
int	main()
{
	int			fd;
	const char	*file1 = "test_iiifile";

	fd = open(file1, O_RDONLY);

//	printlines(fd, BUFFER_SIZE, buf);
//	printline(fd, BUFFER_SIZE);
	printf("%i", fd);

	close(fd);
}
