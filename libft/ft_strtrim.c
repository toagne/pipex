/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:18:19 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/05 17:30:08 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	start_check(char *s1, char *set)
{
	size_t	start;
	int		n;
	int		n1;

	start = 0;
	n = 0;
	n1 = 0;
	while (set[n] != '\0')
	{
		if (s1[n1] == set[n])
		{
			start++;
			n = 0;
			n1++;
		}
		else
			n++;
	}
	return (start);
}

static size_t	end_check(char *s1, char *set, size_t s1_len)
{
	int		n;
	size_t	end;

	n = 0;
	end = 0;
	while (set[n] != '\0')
	{
		if (s1[s1_len - 1] == set[n])
		{
			s1_len--;
			end++;
			n = 0;
		}
		else
			n++;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	s1_len;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	start = start_check((char *)s1, (char *)set);
	end = end_check((char *)s1, (char *)set, s1_len);
	str = ft_substr(s1, start, (s1_len - start - end));
	if (!str)
		return (NULL);
	return (str);
}
/*
int main(void)
{
//	char *s1 = " lorem ipsum dolor sit amet";
	char *set = "l ";
	char *str = ft_strtrim(NULL, set);
	printf("%s\n", str);
}
*/
