/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr >              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:40:38 by bince             #+#    #+#             */
/*   Updated: 2023/11/13 21:53:58 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		str_size;
	char	*genstr;

	i = 0;
	if (!s || !f)
		return (NULL);
	str_size = ft_strlen((char *)s);
	genstr = malloc(sizeof(char) * (str_size + 1));
	if (!genstr)
		return (NULL);
	while (i < str_size)
	{
		genstr[i] = f(i, s[i]);
		i++;
	}
	genstr[i] = '\0';
	return (genstr);
}
