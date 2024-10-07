/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr >              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:41:05 by bince             #+#    #+#             */
/*   Updated: 2023/11/13 21:54:07 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*terminated_str(char *str, int j)
{
	str[j] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	s_size;
	char	*substr;

	if (!s)
		return (NULL);
	s_size = ft_strlen((char *)s);
	if (start > s_size)
		return (ft_strdup("\0"));
	if (len >= s_size)
		len = s_size - start;
	i = 0;
	j = 0;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[i])
	{
		if (j < len && i >= start)
			substr[j++] = s[i];
		i++;
	}
	return (terminated_str(substr, j));
}
