#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
    size_t i;
    unsigned char *ptr;

    ptr = (unsigned char *)s;
    i = 0;
    while(i < n)
    {
        ptr[i] = 0;
        i++;
    }
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	buffer[6] = "hello";
	size_t	i;

	ft_bzero(buffer, 3);
	i = 0;
	while (i < 6)
	{
        // should print \0 \0 \0 l o \0 
		if (buffer[i] == '\0')
			printf("\\0 ");
		else
			printf("%c ", buffer[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/