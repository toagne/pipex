/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:04:58 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/05 16:24:05 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_n_len(int n)
{
	int	n_len;

	n_len = 0;
	if (n == 0)
		n_len = 1;
	else
	{
		while (n != 0)
		{
			n /= 10;
			n_len++;
		}
	}
	return (n_len);
}

static char	*n_neg(char *str, int n, int n_len)
{
	if (n == INT_MIN)
	{
		str[0] = '-';
		str[1] = '2';
		n = -147483648;
	}
	else
		str[0] = '-';
	str[n_len + 1] = '\0';
	n *= -1;
	while (n != 0)
	{
		str[n_len] = (n % 10) + '0';
		n /= 10;
		n_len--;
	}
	return (str);
}

static char	*n_pos(char *str, int n, int n_len)
{
	str[n_len] = '\0';
	if (n == 0)
		str[0] = '0';
	else
	{
		while (n != 0)
		{
			str[n_len - 1] = (n % 10) + '0';
			n /= 10;
			n_len--;
		}
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		n_len;
	char	*str;

	n_len = check_n_len(n);
	if (n < 0)
	{
		str = (char *)malloc(n_len * sizeof(char) + 2);
		if (!str)
			return (NULL);
		n_neg(str, n, n_len);
	}
	else
	{
		str = (char *)malloc(n_len * sizeof(char) + 1);
		if (!str)
			return (NULL);
		n_pos(str, n, n_len);
	}
	return (str);
}
/*
int main(void)
{
	int n = 0;
	char *str = ft_itoa(n);
	printf("%s\n", str);
}
*/
