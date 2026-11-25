/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelau <jelau@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:45:51 by jelau             #+#    #+#             */
/*   Updated: 2026/11/24 18:06:03 by jelau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

#include <stddef.h>

int     ft_isalpha(int c);                                      //t
int     ft_isdigit(int c);                                      //t
int     ft_isalnum(int c);                                      //t
int     ft_isascii(int c);                                      //t
int     ft_isprint(int c);                                      //t
size_t  ft_strlen(const char *s);                               //t
void    *ft_memset(void *s, int c, size_t n);                   //t
void    ft_bzero(void *s, size_t n);                            //t
void    *ft_memcpy(void *dest, const void *src, size_t n);      //t
void	*ft_memmove(void *dest, const void *src, size_t n);     //t
size_t  ft_strlcpy(char *dst, const char *src, size_t size);    //t
size_t  ft_strlcat(char *dst, const char *src, size_t size);    //t
int     ft_toupper(int c);                                      //t
int     ft_tolower(int c);                                      //t
char    *ft_strchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);
int     ft_strncmp(const char *s1, const char *s2, size_t n);   //
void    *ft_memchr(const void *s, int c, size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
char    *ft_strnstr(const char *big, const char *little, size_t len);
int     ft_atoi(const char *nptr);                              //t
void    *ft_calloc(size_t nmemb, size_t size);
char    *ft_strdup(const char *s);                              //

#endif