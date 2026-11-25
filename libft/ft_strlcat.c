/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelau <jelau@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:45:23 by jelau             #+#    #+#             */
/*   Updated: 2026/11/24 14:45:23 by jelau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;

	len_src = 0;
	while (src[len_src] != '\0')
	{
		len_src++;
	}
	len_dst = 0;
	while (len_dst < size && dst[len_dst] != '\0')
	{
		len_dst++; 
	}

	if (len_dst == size)
		return (size + len_src);

	i = 0;
	while (src[i] != '\0' && len_dst + i + 1 < size)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';

	return (len_dst + len_src);


	// char buffer13_src[5] = "AA";
	// char buffer13_dest[5] = "BB";
	// size_t result13 = strlcat(buffer13_dest, buffer13_src, 5); // returns 4 and buffer13_dest = { 'B', 'B', 'A', 'A', '\0' }
}
