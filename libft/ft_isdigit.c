/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:50:38 by mpellegr          #+#    #+#             */
/*   Updated: 2024/04/22 11:55:05 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int arg)
{
	if (arg >= 48 && arg <= 57)
		return (1);
	return (0);
}
/*
int main(void)
{
	char c;

	c = '1';
	printf("isdigit: %d\n", isdigit(c));
	printf("ft_isdigit: %d\n", ft_isdigit(c));

	c = 'f';
 	printf("isdigit: %d\n", isdigit(c));
 	printf("ft_isdigit: %d\n", ft_isdigit(c));
}
*/
