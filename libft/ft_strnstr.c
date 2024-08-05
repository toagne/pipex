/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:22:41 by mpellegr          #+#    #+#             */
/*   Updated: 2024/04/23 14:36:48 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	size_t	n;

	if (!haystack && !len)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len--)
	{
		n = 0;
		while (haystack[n] == needle[n] && needle[n] != '\0' && n <= len)
		{
			if (needle[n + 1] == '\0')
				return ((char *)haystack);
			n++;
		}
		haystack++;
	}
	return (NULL);
}
/*
int main(void)
{
	char str[20] = "ciao";
	char to_find[10] = "a";
	long n = -1;
    printf("%s\n", strnstr(str, to_find, n));
	printf("%p\n", strnstr(str, to_find, n));
	printf("%s\n", ft_strnstr(str, to_find, n));
	printf("%p\n", ft_strnstr(str, to_find, n));
}
*/
