/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:53:37 by mpellegr          #+#    #+#             */
/*   Updated: 2024/04/29 11:32:36 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(del)(lst->content);
	free(lst);
	lst = NULL;
}
/*
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
	lst->next = lst1;
	lst1->next = lst2;
	printf("%s\n", lst->content);
	printf("%s\n", lst1->content);
	printf("%s\n", lst2->content);
	ft_lstdelone(lst1, ft_free);
	printf("\n%s\n", lst->content);
	printf("%s\n", lst1->content);
	printf("%s\n", lst2->content);
}
*/
