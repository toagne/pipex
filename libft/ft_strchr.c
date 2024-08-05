/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:41:18 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/03 09:52:46 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*str_ptr;

	str_ptr = (char *)str;
	while (*str_ptr - 1)
	{
		if ((char)c == '\0')
		{
			if (*str_ptr == (char)c)
				return (str_ptr);
			str_ptr++;
		}
		else
		{
			if (*str_ptr == '\0')
				return (NULL);
			if (*str_ptr == (char)c)
				return (str_ptr);
			str_ptr++;
		}
	}
	return (NULL);
}
/*
int main(void)
{
	char c = '\0';
	char *str = "teste";
	printf("%p\n", strchr(str, c));
	printf("%p\n", ft_strchr(str, c));
}
*/
