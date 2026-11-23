#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *dest_temp;
    unsigned char *src_temp;
    size_t i;

    // check for dest and src to be not NULL. why?
    dest_temp = (unsigned char *)dest;
	src_temp = (const unsigned char *)src;
    i = 0;
    while(i < n)
    {
        dest_temp[i] = src_temp[i];
        i++;
    }
    return (dest);
}

#include <stdio.h>
#include <string.h>

int main(void)
{
    char src_buf0[6] = "aaaaa";
    char dest_buf0[6] = "bbbbb";
    memcpy(dest_buf0, src_buf0, 3);
    printf("src_buf0=%s, dest_buf0=%s\n", src_buf0, dest_buf0);

    char src_buf[6] = "aaaaa";
    char dest_buf[6] = "bbbbb";
    ft_memcpy(dest_buf, src_buf, 3);
    printf("src_buf=%s, dest_buf=%s\n", src_buf, dest_buf);

    # need to test for cases where the inputs are null pointers

    return (0);
}