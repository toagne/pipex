/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:25:02 by mpellegr          #+#    #+#             */
/*   Updated: 2024/04/22 16:27:11 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
/*
int main(void)
{
	char c;

	c = 'd';
	printf("%c\n", ft_tolower(c));

	c = 'D';
    printf("%c\n", ft_tolower(c));

	c = '+';
    printf("%c\n", ft_tolower(c));
}
*/
