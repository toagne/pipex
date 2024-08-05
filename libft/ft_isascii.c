/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:04:48 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/07 10:15:24 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int arg)
{
	if (arg >= 0 && arg <= 127)
		return (1);
	return (0);
}
/*
int main(void)
{
	unsigned char c;

	c = 'f';
	printf("%d\n", isascii(c));
	printf("%d\n", ft_isascii(c));

	c = 'å';
	printf("%d\n", isascii(c));
	printf("%d\n", ft_isascii(c));
}
*/
