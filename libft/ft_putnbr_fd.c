/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:30:40 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/03 10:30:50 by mpellegr         ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	char	nb[12];
	int		n_len;
	int		c;

	c = 0;
	n_len = check_n_len(n);
	if (n < 0)
		n_neg(nb, n, n_len);
	else
		n_pos(nb, n, n_len);
	while (nb[c] != '\0')
	{
		write (fd, &nb[c], 1);
		c++;
	}
}
/*
int main(void)
{
	int n = INT_MIN;
	int fd = 1;
	ft_putnbr_fd(n, fd);
}
*/
