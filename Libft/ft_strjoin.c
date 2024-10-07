/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr >              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:39:45 by bince             #+#    #+#             */
/*   Updated: 2023/11/13 17:16:39 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_size;
	int		s2_size;
	char	*joinstr;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
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
