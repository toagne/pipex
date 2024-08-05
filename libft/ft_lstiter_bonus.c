/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:47:54 by mpellegr          #+#    #+#             */
/*   Updated: 2024/04/29 12:11:00 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		(f)(lst->content);
		lst = lst->next;
	}
}
/*
void	ft_1(void *lst)
{
	char *str;

	str = (char *)lst;
	str[0] = '1';
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
	ft_lstiter(lst, ft_1);
    printf("\n%s\n", lst->content);
	printf("%s\n", lst1->content);
	printf("%s\n", lst2->content);
}
*/
