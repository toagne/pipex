/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:23:13 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/03 10:33:52 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	n;

	n = 0;
	while (lst)
	{
		lst = lst->next;
		n++;
	}
	return (n);
}
/*
int main(void)
{
//	char *str = "ciao";
//	char *str1 = "come";
//	char *str2 = "stai?";
//	t_list *lst = ft_lstnew(str);
//	t_list *lst1 = ft_lstnew(str1);
//	t_list *lst2 = ft_lstnew(str2);
//	lst->next = lst1;
//	lst1->next = lst2;
	printf("%d\n", ft_lstsize(NULL));
}
*/
