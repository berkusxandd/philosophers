/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:26:07 by bince             #+#    #+#             */
/*   Updated: 2024/08/04 18:06:21 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*first;
// 	t_list	*new;

// 	if (!f || !del)
// 		return (NULL);
// 	first = NULL;
// 	while (lst)
// 	{
// 		new = ft_lstnew((*f)(lst->content));
// 		if (!new)
// 		{
// 			while (first)
// 			{
// 				new = first->next;
// 				(*del)(first->content);
// 				free(first);
// 				first = new;
// 			}
// 			lst = NULL;
// 			return (NULL);
// 		}
// 		ft_lstadd_back(&first, new);
// 		lst = lst->next;
// 	}
// 	return (first);
// }
