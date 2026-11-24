#include "libft.h"

size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t j;

    i = 0;
    while(i < size - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    j = 0;
    while(src[j] != '\0')
    {
        j++;
    }
    return (j);
}

#include <stdio.h>
#include <bsd/string.h>

int main(void)
{
    size_t result0= 0;
    char src_buf0[6] = "aaaaa";
    char dest_buf0[6] = "bbbbb";
    result0 = strlcpy(dest_buf0, src_buf0, 3);
    printf("src_buf0=%s, dest_buf0=%s, result0=%zu\n", src_buf0, dest_buf0, result0);

    size_t result= 0;
    char src_buf[6] = "aaaaa";
    char dest_buf[6] = "bbbbb";
    result = ft_strlcpy(dest_buf, src_buf, 3);
    printf("src_buf=%s, dest_buf=%s, result=%zu\n", src_buf, dest_buf, result);

    return (0);
}