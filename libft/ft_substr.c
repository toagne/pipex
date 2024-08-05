/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:16:53 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/05 17:32:52 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		n;
	size_t	s_len;

	if (!s)
		return (NULL);
	n = 0;
	s_len = ft_strlen(s);
	if (start > s_len)
		len = 0;
	else if (len > (s_len - start))
		len = s_len - start;
	substr = (char *)malloc(len * sizeof(char) + 1);
	if (!substr)
		return (NULL);
	substr[len] = '\0';
	while ((len--))
	{
		substr[n] = s[start];
		start++;
		n++;
	}
	return (substr);
}
/*
int main(void)
{
	char *s = "hello how are you?";
	int start = 50;
	int len = 10;
	char *substr = ft_substr(s, start, len);
	int n = 0;
	while (substr[n] != '\0')
	{
		write (1, &substr[n], 1);
		n++;
	}
}
*/
