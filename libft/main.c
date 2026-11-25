#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
	// ft_isalpha(), ft_isdigit(), ft_isalnum(), ft_isascii(), ft_isprint()
	int i;
	for (i = -1; i < 256; i++) // -1 is included as documentation says unsigned int or EOF, which is -1.
	{
		assert((ft_isalpha(i) != 0) == (isalpha(i) != 0));
		assert((ft_isdigit(i) != 0) == (isdigit(i) != 0));
		assert((ft_isalnum(i) != 0) == (isalnum(i) != 0));
		assert((ft_isascii(i) != 0) == (isascii(i) != 0));
		assert((ft_isprint(i) != 0) == (isprint(i) != 0));
	}

	// ft_atoi()
	assert(ft_atoi("") == atoi(""));
	assert(ft_atoi("1") == atoi("1"));
	assert(ft_atoi("-1") == atoi("-1"));
	assert(ft_atoi("0") == atoi("0"));
	assert(ft_atoi("b+-1") == atoi("b+-1"));
	assert(ft_atoi(" \f\n\r\t\v+1") == atoi(" \f\n\r\t\v+1"));
	assert(ft_atoi(" 1") == atoi(" 1"));
	assert(ft_atoi("   +1") == atoi("   +1"));
	assert(ft_atoi("   --1") == atoi("   --1"));
	assert(ft_atoi("  --2b1") == atoi("  --2b1"));
	assert(ft_atoi("1\n1") == atoi("1\n1"));
	assert(ft_atoi("- +") == atoi("- +"));
	assert(ft_atoi("- -2") == atoi("- -2"));
	assert(ft_atoi(" + 2") == atoi(" + 2"));
	assert(ft_atoi(" 7  ") == atoi(" 7  "));
	assert(ft_atoi("  1-") == atoi("  1-"));

	// ft_strlen() 
	assert(ft_strlen("") == strlen(""));
	assert(ft_strlen("skibidi") == strlen("skibidi"));
	assert(ft_strlen(" \0 ") == strlen(" \0 "));

	// ft_memset()
    char buffer1[6] = "AAAAA";
    char buffer2[6] = "AAAAA";
    assert(ft_memset(buffer1, 'B', 3) == buffer1);  // {'B', 'B', 'B', 'A', 'A', '\0'}
    memset(buffer2, 'B', 3);  // {'B', 'B', 'B', 'A', 'A', '\0'}
    assert(strcmp(buffer1, buffer2) == 0);

	// ft_bzero()
	char buffer3[6] = "AAAAA";
	ft_bzero(buffer3, 3); // {'\0', '\0', '\0', 'A', 'A', '\0'}
	char buffer4[6] = "AAAAA";
	bzero(buffer4, 3); // {'\0', '\0', '\0', 'A', 'A', '\0'}
	for (i = 0; i < 5; i++)
	{
		assert(buffer3[i] == buffer4[i]);
	}

	// ft_memcpy()
	char buffer5_src[6] = "AAAAA";
    char buffer5_dest[6] = "BBBBB";
	memcpy(buffer5_dest, buffer5_src, 2); // {'A', 'A', 'B', 'B', 'B', '\0'}
    char buffer6_src[6] = "AAAAA";
    char buffer6_dest[6] = "BBBBB";
    ft_memcpy(buffer6_dest, buffer6_src, 2); // {'A', 'A', 'B', 'B', 'B', '\0'}
	for (i = 0; i < 6; i++)
	{
		assert(buffer5_src[i] == buffer6_src[i]);
		assert(buffer5_dest[i] == buffer6_dest[i]);
	}

	// ft_memmove()
	char	buffer7[] = "ABCDEF";
	memmove(buffer7 + 2, buffer7, 4); // {'A', 'B', 'A', 'B', 'C', 'D', '\0'}
	char	buffer8[] = "ABCDEF";
	ft_memmove(buffer8 + 2, buffer8, 4); // {'A', 'B', 'A', 'B', 'C', 'D', '\0'}
	assert(strcmp(buffer7, "ABABCD") == 0);
	assert(strcmp(buffer7, buffer8) == 0);

	char	buffer9[] = "ABCDEF";
	memmove(buffer9 , buffer9 + 2, 4); // {'C', 'D', 'E', 'F', 'E', 'F', '\0'}
	char	buffer10[] = "ABCDEF";
	ft_memmove(buffer10, buffer10 + 2, 4); // {'C', 'D', 'E', 'F', 'E', 'F', '\0'}
	assert(strcmp(buffer9, "CDEFEF") == 0);
	assert(strcmp(buffer9, buffer10) == 0);

	// ft_strlcpy()
	char buffer11_src[5] = "AAAA";
	char buffer11_dest[5] = "BBBB";
	size_t result11 = strlcpy(buffer11_dest, buffer11_src, 3); // returns 4 and buffer11_dest = { 'A', 'A', '\0', 'B', '\0' }
	char buffer12_src[5] = "AAAA";
	char buffer12_dest[5] = "BBBB";
	size_t result12 = ft_strlcpy(buffer12_dest, buffer12_src, 3);  // returns 4 and buffer12_dest = { 'A', 'A', '\0', 'B', '\0' }
	assert(result11 == result12);
	for (i = 0; i < 5; i++)
	{
		assert(buffer11_src[i] == buffer12_src[i]);
		assert(buffer11_dest[i] == buffer12_dest[i]);
	}

	// ft_strlcat()
	// returns initial length of dst + length of src

	char buffer13_src[5] = "AA";
	char buffer13_dest[5] = "BB";
	size_t result13 = strlcat(buffer13_dest, buffer13_src, 5); // returns 4 and buffer13_dest = { 'B', 'B', 'A', 'A', '\0' }
	char buffer14_src[5] = "AA";
	char buffer14_dest[5] = "BB";
	size_t result14 = ft_strlcat(buffer14_dest, buffer14_src, 5); // returns 4 and buffer14_dest = { 'B', 'B', 'A', 'A', '\0' }
	assert(result13 == result14);
	for (i = 0; i < 5; i++)
	{
		assert(buffer13_src[i] == buffer14_src[i]);
		assert(buffer13_dest[i] == buffer14_dest[i]);
	}


	char buffer15_src[5] = "AA";
	char buffer15_dest[5] = "BB";
	size_t result15 = strlcat(buffer15_dest, buffer15_src, 4); // returns 4 and buffer15_dest = { 'B', 'B', 'A', '\0', '\0' }
	char buffer16_src[5] = "AA";
	char buffer16_dest[5] = "BB";
	size_t result16 = ft_strlcat(buffer16_dest, buffer16_src, 4); // returns 4 and buffer16_dest = { 'B', 'B', 'A', '\0', '\0' }
	assert(result15 == result16);
	for (i = 0; i < 5; i++)
	{
		assert(buffer15_src[i] == buffer16_src[i]);
		assert(buffer15_dest[i] == buffer16_dest[i]);
	}

	// ft_toupper(), ft_tolower()
	char *buffer17 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-!@#$";
	for (i = 0; buffer17[i] != '\0'; i++)
	{
		assert(toupper(buffer17[i]) == ft_toupper(buffer17[i]));
		assert(tolower(buffer17[i]) == ft_tolower(buffer17[i]));
	}





	printf("All tests passed\n");
	return (0);
}


// 	printf("%d,%d\n",ft_atoi(""),atoi(""));