/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:56:05 by bince             #+#    #+#             */
/*   Updated: 2024/08/04 17:50:20 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*prev;
	t_list	*next;

	if (lst == NULL || del == NULL)
		return ;
	prev = lst->prev;
	next = lst->next;
	if (lst->var)
		del(lst->var);
	if (lst->value)
		del(lst->value);
	free(lst);
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
}
