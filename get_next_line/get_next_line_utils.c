/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:11:45 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/20 12:21:33 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_lengnl(char *str)
{
	size_t	n;

	n = 0;
	if (!str)
		return (0);
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*ft_strchr_with_prot(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*n_f(char *str1, char *str2)
{
	free(str1);
	free(str2);
	str1 = NULL;
	return (str1);
}

char	*pop_bufer(char *new_str, char *s1, char *s2)
{
	size_t	n;
	size_t	n1;

	n = 0;
	n1 = 0;
	while (s1[n] != '\0')
		new_str[n++] = s1[n1++];
	n1 = 0;
	while (s2[n1] != '\0')
		new_str[n++] = s2[n1++];
	new_str[n] = '\0';
	free(s1);
	return (new_str);
}

char	*create_buffer(char *str1, char *str2)
{
	char	*new_buffer;
	size_t	tot_len;

	if (!str1)
	{
		str1 = (char *)malloc(sizeof(char) * 1);
		if (!str1)
		{
			free(str2);
			return (NULL);
		}
		str1[0] = '\0';
	}
	if (!str2 || !str1)
		return (NULL);
	tot_len = ft_lengnl(str1) + ft_lengnl(str2);
	new_buffer = (char *)malloc(sizeof(char) * (tot_len + 1));
	if (!new_buffer)
	{
		str1 = n_f(str1, str2);
		return (NULL);
	}
	new_buffer = pop_bufer(new_buffer, str1, str2);
	return (new_buffer);
}
