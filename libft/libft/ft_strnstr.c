/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelau <jelau@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:45:33 by jelau             #+#    #+#             */
/*   Updated: 2026/11/24 14:45:33 by jelau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;
	size_t	len_big;
	size_t	i;

	len_little = 0;
	while (little[len_little] != '\0')
		len_little++;
	if (len_little == 0)
		return ((char *)big);
	len_big = 0;
	while (len_big != '\0')
		len_big++;
	i = 0;
	while (len_little + i <= len && big[i] != '\0')
	{
		if (ft_strncmp(big + i, little, len_little) == 0)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
