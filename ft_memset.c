#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		((char *)b)[i++] = c;
	return (b);
}

/*
#include <stdio.h>
int	main(void)
{
	char	mem[256] = {0};

	ft_memset(mem, 97, 5);
	printf("%d\n", (int)mem[0]);
	printf("%d\n", (int)mem[1]);
	printf("%d\n", (int)mem[2]);
	printf("%d\n", (int)mem[3]);
	printf("%d\n", (int)mem[4]);
	printf("%d\n", (int)mem[5]);
	printf("%d\n", (int)mem[6]);
}
*/
