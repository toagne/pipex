/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:07:16 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/03 10:05:06 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a1;
	unsigned char	*a2;

	a1 = (unsigned char *) s1;
	a2 = (unsigned char *) s2;
	while (n--)
	{
		if (*a1 != *a2)
			return (*a1 - *a2);
		a1++;
		a2++;
	}
	return (0);
}
/*
int main(void)
{
	char s1[] = "";
	char s2[] = "";
	int n = 10;
	printf("%d\n", ft_memcmp(s1, s2, n));
	printf("%d", memcmp(s1, s2, n));
}
*/
