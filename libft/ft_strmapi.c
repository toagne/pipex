/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:09:54 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/02 18:04:43 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		n;

	if (!s)
		return (NULL);
	n = 0;
	str = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (*s)
	{
		str[n] = f(n, (char)s[0]);
		n++;
		s++;
	}
	str[n] = '\0';
	return (str);
}
/*
char ft_tolower_1(unsigned int n, char c)
{
	return (c +	n);
}

int main(void)
{
//	char *s = "abcdef";
	char *str = ft_strmapi(NULL, ft_tolower_1);
	printf("%s\n", str);
}
*/
