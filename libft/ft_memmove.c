/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelau <jelau@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:45:15 by jelau             #+#    #+#             */
/*   Updated: 2026/11/24 17:31:35 by jelau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *dest_temp;
	const unsigned char *src_temp;
	size_t i;

	dest_temp = (unsigned char *)dest;
	src_temp = (const unsigned char *)src;
	if (dest_temp > src_temp)
	{
		i = n;
		while (i > 0)
		{
			dest_temp[i - 1] = src_temp[i - 1];
			i--;
		}
	} else
	{
		i = 0;
		while (i < n)
		{
			dest_temp[i] = src_temp[i];
			i++;
		}		
	}
    return (dest);
}
