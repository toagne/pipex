/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:58:53 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/03 12:33:02 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*boh;
	t_list	*boh1;

	if (!lst || !del || !(*lst))
		return ;
	boh = *lst;
	while (boh != NULL)
	{
		boh1 = boh->next;
		del(boh->content);
		free(boh);
		boh = boh1;
	}
	*lst = NULL;
}
/*
void	ft_free(void *content)
{
	free(content);
}

int main()
{
	// Test case 1: lst is NULL
    ft_lstclear(NULL, &ft_free);

	// Test case 2: del is NULL
	t_list *list2 = malloc(sizeof(t_list));
	list2->content = malloc(10);
	list2->next = NULL;
	ft_lstclear(&list2, NULL);

	// Test case 3: *lst (content of list) is NULL
	t_list *list3 = NULL;
	ft_lstclear(&list3, &ft_free);

	// add this under if (!lst || !del || !(*lst))  to test
	// if (!lst)
    //        printf("lst failed\n");
    //    else if (!del)
    //        printf("del failed\n");
    //    else if (!(*lst))
    //        printf("*lst failed\n");

}
*/
/*
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
    ft_lstclear(&lst1, ft_free);
	if (lst)
    	printf("\n%s\n", lst->content);
	else
		printf("NULL");
	if (lst1)
		printf("%s\n", lst1->content);
    else 
        printf("NULL");
	if (!str2)
        printf("NULL");
}
*/
