/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:16:07 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/07 10:16:16 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_real_atoi(const char *str, int m, long long int n)
{
	long	check;

	while (*str >= 48 && *str <= 57)
	{
		check = n * 10 + (*str - '0');
		if (check / 10 != n && m == 0)
			return (-1);
		else if (check / 10 != n && m == 1)
			return (0);
		str++;
		n = check;
	}
	return (n);
}

int	ft_atoi(const char *str)
{
	long long int	n;
	int				m;

	n = 0;
	m = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 45)
	{
		str++;
		m++;
	}
	else if (*str == 43)
		str++;
	n = ft_real_atoi(str, m, n);
	if (m == 1)
		return (-n);
	else
		return (n);
}
/*
int main(void)
{
	char *str = "0";
	printf("atoi: %d\n", atoi(str));
	printf("ft_atoi: %d\n", ft_atoi(str));

	str = "-21474836481111111111";
	printf("atoi: %d\n", atoi(str));
    printf("ft_atoi: %d\n", ft_atoi(str));

	str = "2147483647";
    printf("atoi: %d\n", atoi(str));
    printf("ft_atoi: %d\n", ft_atoi(str));

	str = "–2147483648";
    printf("atoi: %d\n", atoi(str));
    printf("ft_atoi: %d\n", ft_atoi(str));

	str = "9223372036854775807";
    printf("atoi: %d\n", atoi(str));
    printf("ft_atoi: %d\n", ft_atoi(str));

	str = "-9223372036854775808";
    printf("atoi: %d\n", atoi(str));
    printf("ft_atoi: %d\n", ft_atoi(str));
}
*/
