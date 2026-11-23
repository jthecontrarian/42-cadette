#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
    size_t i;
    unsigned char *ptr;

    ptr = (unsigned char *)s;
    i = 0;
    while(i < n)
    {
        ptr[i] = (unsigned char)c;
        i++;
    }
    return (s);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char buffer[6] = "hello";
    void *returned = memset(buffer, 'X', 3);
    
    printf("Buffer: %s (expected: XXXlo)\n", buffer);
    printf("Return matches: %s\n", (returned == buffer) ? "YES" : "NO"); // To test so that we have returned the pointer to the original position

    char buffer2[6] = "hello";
    void *returned2 = memset(buffer2, 'X', 3);
    printf("Buffer: %s (expected: XXXlo)\n", buffer2);
    printf("Return matches: %s\n", (returned2 == buffer2) ? "YES" : "NO"); // To test so that we have returned the pointer to the original position

    return (0);
}
*/