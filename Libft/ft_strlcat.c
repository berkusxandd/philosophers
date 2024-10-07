/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr >              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:40:26 by bince             #+#    #+#             */
/*   Updated: 2023/11/13 21:23:48 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_size;
	size_t	src_size;

	if (size == 0 && (dest == NULL || src == NULL))
		return (0);
	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	if (dest_size >= size)
		return (size + src_size);
	if (dest_size + src_size < size)
	{
		ft_memcpy(dest + dest_size, src, src_size + 1);
	}
	else
	{
		ft_memcpy(dest + dest_size, src, size - dest_size - 1);
		dest[size - 1] = '\0';
	}
	return (dest_size + src_size);
}
