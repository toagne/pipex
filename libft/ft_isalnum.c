/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:57:53 by mpellegr          #+#    #+#             */
/*   Updated: 2024/04/22 12:04:34 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int arg)
{
	if (ft_isalpha(arg) == 1 || ft_isdigit(arg) == 1)
		return (1);
	return (0);
}
/*
int main(void)
{
	char c;

	c = 'f';
	printf("%d\n", isalnum(c));
	printf("%d\n", ft_isalnum(c));

	c = '1';
	printf("%d\n", isalnum(c));
	printf("%d\n", ft_isalnum(c));

	c = '+';
	printf("%d\n", isalnum(c));
	printf("%d\n", ft_isalnum(c));
}
*/
