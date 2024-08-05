/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:09:57 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/03 10:00:52 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*a1;
	unsigned char	*a2;
	size_t			nb;

	nb = 0;
	a1 = (unsigned char *) s1;
	a2 = (unsigned char *) s2;
	while ((a1[nb] != '\0' || a2[nb] != '\0') && nb < n)
	{
		if (a1[nb] != a2[nb])
		{
			return (a1[nb] - a2[nb]);
		}
		nb++;
	}
	return (0);
}
/*
int	main(void)
{
	char s1[] = "ciao";
	char s2[] = "ciaoi";
	int n = 0;
	printf("%d\n", ft_strncmp(s1, s2, n));
	printf("%d", strncmp(s1, s2, n));
}
*/
