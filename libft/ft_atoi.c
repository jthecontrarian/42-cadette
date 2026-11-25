/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelau <jelau@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:44:31 by jelau             #+#    #+#             */
/*   Updated: 2026/11/24 14:59:56 by jelau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

static int	is_operator(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}

static int	is_number(char c)
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
		i++;
	if (is_operator(nptr[i]))
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
