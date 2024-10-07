/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr >              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:40:51 by bince             #+#    #+#             */
/*   Updated: 2023/11/13 14:41:56 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	i++;
	while (i > 0)
	{
		i--;
		if (s[i] == (char)c)
			return ((char *)(s + i));
	}
	if (s[0] == (char)c)
		return ((char *)s);
	return (NULL);
}
