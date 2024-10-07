/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:56:40 by bince             #+#    #+#             */
/*   Updated: 2024/08/13 12:48:39 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *var, char *value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->var = NULL;
	new->value = NULL;
	if (var)
		new->var = ft_strdup(var);
	if (value)
		new->value = ft_strdup(value);
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
