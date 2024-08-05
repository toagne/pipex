/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:09:38 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/03 10:20:15 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*target;

	target = (char *) malloc((ft_strlen(s1)+1) * sizeof(char));
	if (!target)
		return (NULL);
	ft_strlcpy(target, s1, ft_strlen(s1) + 1);
	return (target);
}
/*
int main(void)
{
    char str[] = "hello";
	printf("%s\n", ft_strdup(str));
    printf("%s\n", strdup(str));
	printf("%p\n", ft_strdup(str));
	printf("%p\n", str);
}
*/
