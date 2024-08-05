/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:28:02 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/07 09:36:20 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_check(char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static size_t	check_c_counter(char *s, char c)
{
	int		n;
	size_t	c_counter;

	n = 0;
	c_counter = 0;
	while (s[n] != '\0')
	{
		if (s[n] == c)
		{
			if (n == 0 || s[n] == s[n - 1])
				n++;
			else if (s[n] == c)
			{
				c_counter++;
				n++;
			}
		}
		else
			n++;
	}
	if (s[(ft_strlen(s)) - 1] == c)
		c_counter--;
	return (c_counter);
}

static void	free_arr(char **arr, int n)
{
	while (n > 0)
	{
		n--;
		free (arr[n]);
	}
	free (arr);
}

char	**real_split(char **arr, char *s, char c, size_t c_counter)
{
	size_t	n;
	int		start;
	size_t	len;

	n = 0;
	arr[c_counter] = 0;
	while (n < c_counter)
	{
		start = 0;
		while (*(s + start) && *(s + start) == c)
			start++;
		s = s + start;
		len = len_check((char *)s, c);
		arr[n] = ft_substr((char *)s, 0, len);
		if (!arr[n])
		{
			free_arr(arr, n);
			return (NULL);
		}
		n++;
		s = s + len;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	c_counter;

	if (!s)
		return (NULL);
	if (*s == '\0')
		c_counter = 0 ;
	else
		c_counter = check_c_counter((char *)s, c) + 1;
	arr = (char **)malloc((c_counter + 1) * sizeof(char **));
	if (!arr)
		return (NULL);
	arr = real_split(arr, (char *)s, c, c_counter);
	return (arr);
}
/*
#include <stdio.h>

int main(void)
{
	char *s = "***hello**how*are**you?***";
	char c = '*';
	char **arr;
	arr = ft_split(s, c);
	int n = 0;
	while (arr[n] != '\0')
	{
		printf("%s\n", arr[n]);
		n++;
	}

}
*/
