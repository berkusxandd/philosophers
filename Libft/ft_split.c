/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:39:18 by bince             #+#    #+#             */
/*   Updated: 2024/08/13 11:57:56 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char *str, char set)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != set)
		++i;
	return (i);
}

static char	*word_dupe(char *str, char set)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = ft_wordlen(str, set);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
	{
		free(word);
		return (NULL);
	}
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	return (word);
}

static void	fill_words(char **array, char *str, char set)
{
	int	word_index;
	int	i;

	word_index = 0;
	i = 0;
	while (*str != '\0')
	{
		while (*str == set)
			++str;
		if (*str == '\0')
			break ;
		array[word_index] = word_dupe(str, set);
		if (!array[word_index])
		{
			while (i < word_index)
				free(array[i++]);
			free(array);
			return ;
		}
		++word_index;
		while (*str != '\0' && *str != set)
			++str;
	}
	array[word_index] = NULL;
}

static int	count_words(char *str, char set)
{
	int	num_words;

	num_words = 0;
	while (*str != '\0')
	{
		while (*str == set)
			++str;
		if (*str != '\0')
		{
			++num_words;
			while (*str != '\0' && *str != set)
				++str;
		}
	}
	return (num_words);
}

char	**ft_split(char const *str, char set)
{
	int		num_words;
	char	**array;

	if (!str)
		return (NULL);
	num_words = count_words((char *)str, set);
	array = malloc(sizeof(char *) * (num_words + 1));
	if (!array)
		return (NULL);
	fill_words(array, (char *)str, set);
	return (array);
}
