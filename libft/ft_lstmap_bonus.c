/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:11:12 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/03 12:59:03 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*boh;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		boh = f(lst->content);
		new_node = ft_lstnew(boh);
		if (!new_node)
		{
			del(boh);
			ft_lstclear(&new_lst, (*del));
			return (new_lst);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
/*
void	*ft_1(void *lst)
{
	char *str;

	str = (char *)lst;
	str[0] = '1';
	return (lst);
}

void ft_free(void *content)
{
	free(content);
}

int main(void)
{
    char *str = strdup("ciao");
    char *str1 = strdup("come");
    char *str2 = strdup("stai?");
    t_list *lst = ft_lstnew(str);
    t_list *lst1 = ft_lstnew(str1);
    t_list *lst2 = ft_lstnew(str2);
    t_list *new_lst;
    lst->next = lst1;
    lst1->next = lst2;
    printf("%s\n", lst->content);
    printf("%s\n", lst1->content);
    printf("%s\n", lst2->content);
    new_lst = ft_lstmap(lst, ft_1, ft_free);
    while (new_lst != NULL)
    {
        printf("%s\n", new_lst->content);
        new_lst = new_lst->next;
    }
}
*/
