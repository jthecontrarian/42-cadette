/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelau <jelau@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 15:31:21 by jelau             #+#    #+#             */
/*   Updated: 2026/11/26 14:01:50 by jelau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	back;

	front = 0;
	while (s1[front] != '\0' && ft_strchr(set, s1[front]))
		front++;
	back = ft_strlen(s1);
	while (back > front && ft_strchr(set, s1[back - 1]))
		back--;
	return (ft_substr(s1, front, back - front));
}
