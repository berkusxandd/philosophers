/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr >              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:28:47 by bince             #+#    #+#             */
/*   Updated: 2023/11/13 14:26:22 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*write_digits(int i, int j, long nb, int digit)
{
	char	*str;

	if (j == 0)
		str = malloc(sizeof(char) * (digit + 1));
	else
		str = malloc(sizeof(char) * (digit + 2));
	if (!str)
		return (NULL);
	if (j != 0)
		str[0] = 45;
	while (i >= 10)
	{
		str[j] = ((nb / i) % 10) + 48;
		i /= 10;
		j++;
	}
	str[j++] = ((nb / i) % 10) + 48;
	str[j] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	int		digit;
	char	*str;
	long	nb;

	j = 0;
	digit = 1;
	i = 1;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		j++;
	}
	while (nb / i >= 10)
	{
		i *= 10;
		digit++;
	}
	str = write_digits(i, j, nb, digit);
	if (!str)
		return (NULL);
	return (str);
}
