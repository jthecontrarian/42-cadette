#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include <stdlib.h>
#include "libft.h"

static char	increment_by_num(unsigned int n, char c)
{
	return (c + n);
}

static void increment_by_one(unsigned int i, char *c)
{
	(void)i;
	(*c)++; 
}

static void	print_linked_list(t_list *node)
{
	while (node != NULL)
	{
		printf("content=%s,", (char *)node->content);
		printf("next=%p\n", node->next);
		node = node->next;
	}
}

static void	del_content(void *content)
{
	free(content);
}

static void	*increment_by_one_allocate(void *content)
{
	char	*copy;

	copy = ft_strdup((char *)content);
	if (copy == NULL)
		return (NULL);
	copy++;
	return (copy);
}

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

	// ft_strchr()
	char buffer18[10] = "ABCD";
	assert(strchr(buffer18, 'B') == ft_strchr(buffer18, 'B'));

	char buffer19[10] = "ABCD";
	assert(strchr(buffer19, 'D') == ft_strchr(buffer19, 'D'));

	char buffer20[10] = "ABCD";
	assert(strchr(buffer20, 'E') == ft_strchr(buffer20, 'E'));

	char buffer21[10] = "ABCD";
	assert(strchr(buffer21, '\0') == ft_strchr(buffer21, '\0'));
	
	// ft_strrchr()
	char buffer22[10] = "AABB";
	assert(strrchr(buffer22, 'A') == ft_strrchr(buffer22, 'A'));

	char buffer23[10] = "AABB";
	assert(strrchr(buffer23, 'B') == ft_strrchr(buffer23, 'B'));

	char buffer24[10] = "AABB";
	assert(strrchr(buffer24, 'C') == ft_strrchr(buffer24, 'C'));

	char buffer25[10] = "AABB";
	assert(strrchr(buffer25, '\0') == ft_strrchr(buffer25, '\0'));

	char buffer26[10] = "AA\0BB";
	assert(strrchr(buffer26, '\0') == ft_strrchr(buffer26, '\0'));

	// ft_strncmp()
	assert(strncmp("", "", 3) == ft_strncmp("", "", 3));
	assert(strncmp("abcd", "abcd", 3) == ft_strncmp("abcd", "abcd", 3));
	assert(strncmp("abcz", "abcd", 4) == ft_strncmp("abcz", "abcd", 4));
	assert(strncmp("abcd", "abcz", 4) == ft_strncmp("abcd", "abcz", 4));
	assert(strncmp("abcd", "abcz", 3) == ft_strncmp("abcd", "abcz", 3));
	assert(strncmp("abcd", "abc", 3) == ft_strncmp("abcd", "abc", 3));
	assert(strncmp("abc", "abcd", 3) == ft_strncmp("abc", "abcd", 3));
	assert((strncmp("é", "a", 1) > 0) == (ft_strncmp("é", "a", 1) > 0)); // beyond character code 127

	// ft_memchr()
	char buffer27[5] = "ABCD";
	assert(memchr(buffer27, 'A', 5) == ft_memchr(buffer27, 'A', 5));

	char buffer28[5] = "ABCD";
	assert(memchr(buffer28, 'D', 5) == ft_memchr(buffer28, 'D', 5));

	char buffer29[5] = "ABCD";
	assert(memchr(buffer29, 'D', 2) == ft_memchr(buffer29, 'D', 2));

	char buffer30[5] = "ABCD";
	assert(memchr(buffer30, 'E', 5) == ft_memchr(buffer30, 'E', 5));

	char buffer31[5] = "ABCD";
	assert(memchr(buffer31, 'A', 0) == ft_memchr(buffer31, 'A', 0));

	char buffer32[5] = "ABCD";
	assert(memchr(buffer32, '\0', 5) == ft_memchr(buffer32, '\0', 5));

	char buffer33[5] = "ABCD";
	assert(memchr(buffer33, '\0', 4) == ft_memchr(buffer33, '\0', 4));

	char buffer34[5] = "AB\0D";
	assert(memchr(buffer34, '\0', 5) == ft_memchr(buffer34, '\0', 5));

	// ft_memcmp()
	char buffer35[5] = "ABCD";
	char buffer36[5] = "ABCE";
	assert(memcmp(buffer35, buffer36, 5) == ft_memcmp(buffer35, buffer36, 5));
	char buffer37[5] = "ABCD";
	char buffer38[5] = "ABCE";
	assert(memcmp(buffer37, buffer38, 3) == ft_memcmp(buffer37, buffer38, 3));
	char buffer39[5] = "ABCD";
	char buffer40[5] = "ABCE";
	assert(memcmp(buffer39, buffer40, 0) == ft_memcmp(buffer39, buffer40, 0));
	char buffer41[5] = "é";
	char buffer42[5] = "a";
	assert(memcmp(buffer41, buffer42, 0) == ft_memcmp(buffer41, buffer42, 0)); // beyond character code 127

	// ft_strnstr()
	// If little is an empty string, big is returned;  done
	// If little occurs nowhere in big, NULL is returned; done
	// otherwise a pointer to the first character of the first occurrence of little is returned.
	// a empty big argument gives segmentation fault for strnstr. hence we will not test.
	char buffer43[10] = "AAABBBCCC";
	assert(strnstr(buffer43, "AAA", 10) == ft_strnstr(buffer43, "AAA", 10)); // AAABBBCCC
	assert(strnstr(buffer43, "BBB", 10) == ft_strnstr(buffer43, "BBB", 10)); // BBBCCC
	assert(strnstr(buffer43, "CCC", 10) == ft_strnstr(buffer43, "CCC", 10)); // CCC
	assert(strnstr(buffer43, "CCC", 9) == ft_strnstr(buffer43, "CCC", 9)); // CCC
	assert(strnstr(buffer43, "", 0) == ft_strnstr(buffer43, "", 0)); // AAABBBCCC
	assert(strnstr(buffer43, "", 10) == ft_strnstr(buffer43, "", 10)); // AAABBBCCC
	assert(strnstr(buffer43, "BBB", 10) == ft_strnstr(buffer43, "BBB", 10)); // BBBCCC

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

	// ft_calloc()
	//The memory is set to zero.  If n or size is 0, then cal‐
	//       loc() returns a unique pointer value that can later be successfully passed to free()
	//       If  the  multiplication of n and size would result in integer overflow, then calloc() returns an error.  By contrast, an integer overflow would not be detected in the following call to mal‐
	//       loc(), with the result that an incorrectly sized block of memory would be allocated: malloc(n * size);
	void *ptr0 = ft_calloc(1, 2);
	assert(ptr0 != NULL);
	// for (i = 0; i < 4; i++)
	// {
	// 	printf("%d\n", ((unsigned char *)ptr0)[i]);
	// }
	free(ptr0);


	// ft_strdup()
	char	str[] = "skibidi";
	char	*copy;

	copy = ft_strdup(str);
	assert(copy != NULL);
	assert(copy != str);
	assert(strcmp(copy, str) == 0);
	free(copy);

	// ft_substr()
	assert(ft_strncmp(ft_substr("AABBCC", 2, 2), "BB", 10) == 0);
	assert(ft_substr("AABBCC", 2, 2)[2] == 0); // check for null terminated
	assert(ft_strncmp(ft_substr("AABBCC", 2, 10), "BBCC", 10) == 0);
	assert(ft_strncmp(ft_substr("AABBCC", 6, 2), "", 10) == 0);// test for out of range

	// ft_strjoin()
	assert(ft_strncmp(ft_strjoin("AA", "BB"), "AABB", 5) == 0);
	assert(ft_strjoin("AA", "BB")[4] == 0); // check for null terminated
	assert(ft_strncmp(ft_strjoin("", "BB"), "BB", 3) == 0);
	assert(ft_strncmp(ft_strjoin("AA", ""), "AA", 3) == 0);
	assert(ft_strncmp(ft_strjoin("", ""), "", 1) == 0);

	// ft_strtrim()
	assert(ft_strncmp(ft_strtrim("CC", "AB"), "CC", 10) == 0);
	assert(ft_strncmp(ft_strtrim("AACB", "CA"), "B", 10) == 0);
	assert(ft_strncmp(ft_strtrim("CBAA", "CA"), "B", 10) == 0);
	assert(ft_strncmp(ft_strtrim("AABBCDABAB", "AB"), "CD", 10) == 0);
	assert(ft_strtrim("AABBCDABAB", "AB")[2] == 0); // check for null terminated
	assert(ft_strncmp(ft_strtrim("AABBCABADABAB", "AB"), "CABAD", 15) == 0);
	assert(ft_strncmp(ft_strtrim("", ""), "", 10) == 0);
	assert(ft_strncmp(ft_strtrim("AB", ""), "AB", 10) == 0);
	assert(ft_strncmp(ft_strtrim("", "AB"), "", 10) == 0);
	assert(ft_strncmp(ft_strtrim(" A ", " "), "A", 10) == 0);

	// ft_split()
	char **strs;
	strs = ft_split("aaa bbb ccc ddd ", ' ');
	assert(ft_strncmp(strs[0], "aaa", 4) == 0);
	assert(ft_strncmp(strs[1], "bbb", 4) == 0);
	assert(ft_strncmp(strs[2], "ccc", 4) == 0);
	assert(ft_strncmp(strs[3], "ddd", 4) == 0);

	// ft_itoa()
	assert(ft_strncmp(ft_itoa(-2147483648), "-2147483648", 20) == 0);
	assert(ft_strncmp(ft_itoa(-123), "-123", 20) == 0);
	assert(ft_strncmp(ft_itoa(-1), "-1", 20) == 0);
	assert(ft_strncmp(ft_itoa(0), "0", 20) == 0);
	assert(ft_strncmp(ft_itoa(1), "1", 20) == 0);
	assert(ft_strncmp(ft_itoa(123), "123", 20) == 0);
	assert(ft_strncmp(ft_itoa(2147483647), "2147483647", 20) == 0);

	// ft_strmapi()
	assert(ft_strncmp(ft_strmapi("AAA", increment_by_num), "ABC", 10) == 0);

	// ft_striteri()
	char	str2[4] = "AAA";
	ft_striteri(str2, increment_by_one);
	assert(ft_strncmp(str2, "BBB", 10) == 0);

	// ft_putchar_fd()
	ft_putchar_fd('X', 1);

	// ft_putstr_fd()
	ft_putstr_fd("AAA", 1);

	// ft_putendl_fd()
	ft_putendl_fd("AAA", 1);

	// ft_putnbr_fd()
	ft_putnbr_fd(123, 1);

	// ft_lstnew()
	t_list	*head;
	head = ft_lstnew("A"); // head -> A -> NULL
	print_linked_list(head);
	
	// ft_lstadd_front()
	t_list	*head2;
	t_list	*node2;
	head2 = ft_lstnew("A");
	node2 = ft_lstnew("B");
	ft_lstadd_front(&head2, node2); // head2 -> B -> A -> NULL
	print_linked_list(head2);

	// ft_lstsize()
	printf("size=%d\n", ft_lstsize(head));
	printf("size=%d\n", ft_lstsize(head2));

	// ft_lstlast()
	print_linked_list(ft_lstlast(head2));

	// ft_lstadd_back()
	t_list	*head3;
	head3 = ft_lstnew("C");
	ft_lstadd_back(&head2, head3); // head2 -> B -> A -> C -> NULL
	print_linked_list(head2);

	t_list *head4;
	head4 = NULL; // NULL
	t_list *head5;
	head5 = ft_lstnew("X"); // head5 -> X -> NULL
	ft_lstadd_back(&head4, head5); // head4 -> X -> NULL
	print_linked_list(head4);

	// ft_lstdelone()
	t_list *head6;
	t_list *head7;
	head6 = ft_lstnew(ft_strdup("A"));
	head7 = ft_lstnew(ft_strdup("B"));
	ft_lstadd_back(&head6, head7);
	ft_lstadd_back(&head6, ft_lstnew(ft_strdup("C"))); // head6 -> A -> B -> C -> NULL
	ft_lstdelone(head6, del_content); 
	print_linked_list(head7);

	// ft_lstclear()
	ft_lstclear(&head7, del_content);
	print_linked_list(head7);

	// ft_lstiter()
	t_list *head8;
	head8 = ft_lstnew(ft_strdup("A"));
	ft_lstadd_back(&head8, ft_lstnew(ft_strdup("B")));
	ft_lstadd_back(&head8, ft_lstnew(ft_strdup("C"))); // head8 -> A -> B -> C -> NULL
	ft_lstiter(head8, del_content);

	// ft_lstmap()
	// del is used only when allocation fails at some point during the duplication of lst and application of f on lst
	t_list *head9;
	head9 = ft_lstnew(ft_strdup("A"));
	ft_lstadd_back(&head9, ft_lstnew(ft_strdup("B")));
	ft_lstadd_back(&head9, ft_lstnew(ft_strdup("C"))); // head9 -> A -> B -> C -> NULL
	t_list *head10;
	head10 = ft_lstmap(head9, increment_by_one_allocate, del_content);
	print_linked_list(head9);
	print_linked_list(head10);

	printf("All tests passed\n");
	return (0);
}
