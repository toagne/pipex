/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:25:22 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/03 10:02:31 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_ptr;

	s_ptr = (unsigned char *)s;
	while (n--)
	{
		if (*s_ptr == (unsigned char)c)
			return (s_ptr);
		s_ptr++;
	}
	return (NULL);
}
/*
int main(void)
{
	char *str = "hello";
	char c = '\0';
	printf("%p\n", memchr(str, c, 10));
	printf("%p\n", ft_memchr(str, c, 10));
}
*/
