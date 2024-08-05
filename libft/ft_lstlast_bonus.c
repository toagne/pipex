/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:30:02 by mpellegr          #+#    #+#             */
/*   Updated: 2024/04/26 16:48:55 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int main(void)
{
	char *str = "ciao";
    char *str1 = "come";
    char *str2 = "stai?";
    t_list *lst = ft_lstnew(str);
    t_list *lst1 = ft_lstnew(str1);
    t_list *lst2 = ft_lstnew(str2);
    lst->next = lst1;
    lst1->next = lst2;
    printf("%s\n", ft_lstlast(lst)->content);
}
*/
