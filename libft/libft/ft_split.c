/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelau <jelau@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 15:31:29 by jelau             #+#    #+#             */
/*   Updated: 2026/11/27 20:52:40 by jelau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_substring(char const *str, char c)
{
	int	i;
	int	count;
	int	inside_word;

	i = 0;
	count = 0;
	inside_word = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			inside_word = 0;
		else if (inside_word == 0)
		{
			count++;
			inside_word = 1;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *str, char c)
{
	char	**array;
	int		i;
	int		old_i;
	int		index;

	array = malloc(sizeof(char *) * (count_substring(str, c) + 1));
	if (!array)
		return (NULL);
	i = 0;
	index = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] == '\0')
			break ;
		old_i = i;
		while (str[i] != '\0' && str[i] != c)
			i++;
		array[index] = ft_substr(str, old_i, i - old_i);
		if (!array[index++])
			return (NULL);
	}
	array[index] = NULL;
	return (array);
}
