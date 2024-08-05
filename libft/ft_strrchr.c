/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:53:31 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/03 09:54:31 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*str_ptr;
	size_t	len;

	str_ptr = (char *)str;
	len = ft_strlen(str_ptr) + 1;
	while (len--)
	{
		if (str_ptr[len] == (char)c)
		{
			while (len--)
				str_ptr++;
			return (str_ptr);
		}
	}
	return (NULL);
}
/*
int main(void)
{
	char c = 'e';
	char *str = "teste";
	printf("%p\n", strrchr(str, c));
	printf("%p\n", ft_strrchr(str, c));
}
*/
