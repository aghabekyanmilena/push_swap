/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:23:26 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/29 19:04:00 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_str(char c, char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (1);
	else
		return (0);
}

static size_t	ft_toklen(const char *s, char *c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (in_str(*s, c) == 0)
		{
			++ret;
			while (*s && in_str(*s, c) == 0)
				++s;
		}
		else
			++s;
	}
	return (ret);
}

char	**ft_split(const char *s, char *c)
{
	char	**ret;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	ret = malloc(sizeof(char *) * (ft_toklen(s, c) + 1));
	if (!ret)
		return (0);
	while (*s)
	{
		if (in_str(*s, c) == 0)
		{
			len = 0;
			while (*s && (in_str(*s, c) == 0) && ++len)
				++s;
			ret[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	ret[i] = NULL;
	return (ret);
}
