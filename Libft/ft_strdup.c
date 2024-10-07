/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr >              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:39:36 by bince             #+#    #+#             */
/*   Updated: 2023/11/13 21:24:36 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		strsize;
	int		i;
	char	*str;

	i = 0;
	strsize = ft_strlen(s);
	str = malloc(strsize * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (i < strsize)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
