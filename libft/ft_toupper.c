/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:20:33 by mpellegr          #+#    #+#             */
/*   Updated: 2024/04/22 16:24:48 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
/*
int main(void)
{
	char c;

	c = 'd';
	printf("%c\n", ft_toupper(c));

	c = 'D';
    printf("%c\n", ft_toupper(c));

	c = '+';
    printf("%c\n", ft_toupper(c));
}
*/
