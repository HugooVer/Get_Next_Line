#include<stdio.h>
int	fun()
{
	static int	count;
	count++;
	return (count);
}

int	main()
{
	static char	test;
	printf("%d ", fun());
	printf("%d ", fun());
	printf("%c ", test);
	return 0;
}

