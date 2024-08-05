/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:49:20 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/05 15:35:40 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*boh;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	boh = *lst;
	while (boh->next)
		boh = boh->next;
	boh->next = new;
}
/*
int main(void)
{
    char *str = "ciao";
    char *str1 = "come";
    char *str2 = "stai?";
    char *str3 = "bene";
    t_list *lst = ft_lstnew(str);
    t_list *lst1 = ft_lstnew(str1);
    t_list *lst2 = ft_lstnew(str2);
    t_list *new = ft_lstnew(str3);
    lst->next = lst1;
    lst1->next = lst2;
    ft_lstadd_back(&lst, new);
    while (lst->next)
    {
      printf("%s\n", lst->content);
      lst = lst->next;
    }
    printf("%s\n", lst->content);
}
*/
