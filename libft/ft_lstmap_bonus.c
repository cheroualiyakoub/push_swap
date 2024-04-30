/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:09:39 by ycheroua          #+#    #+#             */
/*   Updated: 2024/04/19 08:08:32 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*start_node;
	void	*temp_content;

	start_node = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		temp_content = ((*f)(lst->content));
		temp = ft_lstnew(temp_content);
		if (!temp)
		{
			(*del)(temp_content);
			ft_lstclear(&start_node, (*del));
			return (NULL);
		}
		ft_lstadd_back(&start_node, temp);
		lst = lst->next;
	}
	return (start_node);
}
