
#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

char    *ft_strjoin(char *s1, char *s2);

int	main()
{
	int			fd;
	size_t		size;
	const char	*file1 = "test_file";
	char		*buf;
	char		*ret;

	fd = open(file1, O_RDONLY);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	size = BUFFER_SIZE;
	ret = "i";

	while(size == BUFFER_SIZE)
	{
		size = read(fd, buf, BUFFER_SIZE);
		buf[size] = '\0';
		ret = ft_strjoin(ret, buf);
//		write(1, buf, size);
	}
	printf("%lu", strlen(ret));
	free(buf);
	close(fd);


}
