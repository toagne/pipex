/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:29:19 by mpellegr          #+#    #+#             */
/*   Updated: 2024/04/26 15:23:01 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int main(void)
{
    char *content = "hello";
    char *content1 = "ciao";
    t_list *new = ft_lstnew(content);
    t_list *list = ft_lstnew(content1);
    ft_lstadd_front(&list, new);
    printf("%s\n", list->content);
    printf("%s\n", list->next->content);
}
*/
