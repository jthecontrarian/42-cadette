/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelau <jelau@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:44:31 by jelau             #+#    #+#             */
/*   Updated: 2026/11/23 14:44:38 by jelau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	is_operator(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}

int	is_number(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	value;
	int	isnegative;

	i = 0;
	value = 0;
	isnegative = 0;
	while (is_space(nptr[i]))
	{
		i++;
	}
	while (is_operator(nptr[i]))
	{
		if (nptr[i] == '-')
			isnegative = 1;
		i++;
	}
	while (is_number(nptr[i]))
		value = value * 10 + (nptr[i++] - '0');
	if (isnegative == 1)
		return (-value);
	else
		return (value);
}

/*
//checks for white-space characters.  In the "C" and  "POSIX"  lo‐
//cales,  these are: space, form-feed ('\f'), newline ('\n'), car‐
//riage return ('\r'), horizontal tab  ('\t'),  and  vertical  tab
//('\v').

// space - operator - number - others



#include <stdio.h>
#include <assert.h>

int	main(void)
{
	printf("%d\n",ft_atoi("1")); //1
	printf("%d\n",ft_atoi("")); //0
	printf("%d\n",ft_atoi("0")); //0
    printf("%d\n",ft_atoi("b+-1")); //0
    printf("%d\n",ft_atoi(" \f\n\r\t\v+1")); //1
    printf("%d\n",ft_atoi(" 1")); //1
    printf("%d\n",ft_atoi("   +1")); //1
    printf("%d\n",ft_atoi("   --1")); //1
    printf("%d\n",ft_atoi("   ---1")); //-1
    printf("%d\n",ft_atoi("   +++1")); //1
    printf("%d\n",ft_atoi("  --2b1")); //2
	printf("%d\n",ft_atoi("  --0b1")); //0
	printf("%d\n",ft_atoi("  --123b1")); //123
	printf("%d\n",ft_atoi("  1-")); //1
	printf("%d\n",ft_atoi("  -1+1")); //-1
	printf("%d\n",ft_atoi("  -1-1")); //-1
	printf("%d\n",ft_atoi("1\n1")); //1
	printf("%d\n",ft_atoi("- +")); //0
	printf("%d\n",ft_atoi("+ -")); //0
	printf("%d\n",ft_atoi("- -2")); //0
	printf("%d\n",ft_atoi(" + 2")); //0
	return (0);
}
*/
