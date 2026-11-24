char    *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <bsd/string.h>

int main(void) {
    const char *str = "libft-test-string";

    printf("%s\n", strnstr(str, "libft", 17));
    printf("%s\n", strnstr(str, "test", 17));
    printf("%s\n", strnstr(str, "string", 17));
    printf("%s\n", strnstr(str, "test", 10));
    printf("%s\n", strnstr(str, "test", 9));
    printf("%s\n", strnstr(str, "", 10));
    printf("%s\n", strnstr(str, "", 0));
    printf("%s\n", strnstr(str, "libft", 0));
    printf("%s\n", strnstr("short", "rt", 100));
    printf("%s\n", strnstr("aaabcabcd", "abcd", 9));
    printf("%s\n", strnstr("", "a", 5));

    return 0;
}