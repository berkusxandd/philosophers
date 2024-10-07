/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:59:48 by bince             #+#    #+#             */
/*   Updated: 2024/06/08 20:53:15 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_size;
	int		s2_size;
	char	*joinstr;
	int		i;

	if (s1 == NULL)
		return ((char *)(s2));
	s1_size = ft_strlen((char *)s1);
	s2_size = ft_strlen((char *)s2);
	i = 0;
	joinstr = malloc(sizeof(char) * (s1_size + s2_size) + 1);
	if (!joinstr)
		return (NULL);
	ft_strlcpy(joinstr, s1, s1_size + 1);
	while (i < s2_size)
	{
		joinstr[i + s1_size] = s2[i];
		i++;
	}
	joinstr[s1_size + s2_size] = '\0';
	return (joinstr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	real_c;

	real_c = c % 256;
	i = 0;
	while (s[i])
	{
		if (s[i] == real_c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0' && s[i] == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = ft_strlen(src);
	if (!dest || !src || n < 1)
		return (src_size);
	while (i < n - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_size);
}
