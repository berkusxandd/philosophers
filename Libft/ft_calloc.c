/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr >              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:57:28 by bince             #+#    #+#             */
/*   Updated: 2023/11/15 12:22:14 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	size_t	total_size;

	if (nmemb > 0 && (size_t)-1 / nmemb < size)
		return (NULL);
	total_size = nmemb * size;
	if (size != 0 && total_size / size != nmemb)
		return (NULL);
	alloc = malloc(total_size);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, total_size);
	return (alloc);
}
