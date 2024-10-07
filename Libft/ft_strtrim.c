/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr >              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:41:01 by bince             #+#    #+#             */
/*   Updated: 2023/11/13 21:57:17 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == (char)set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*terminate_str(char *str, int i)
{
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*trimmed;

	start = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen((char *)s1);
	while (s1[start] && ft_isset((char)s1[start], set))
		start++;
	while (end >= 0 && ft_isset((char)s1[end - 1], set))
		end--;
	if (end < start)
		return (ft_strdup(""));
	trimmed = malloc(sizeof(char) * (end - start) + 1);
	if (!(trimmed))
		return (NULL);
	while (i < (end - start))
	{
		trimmed[i] = s1[start + i];
		i++;
	}
	return (terminate_str(trimmed, i));
}
