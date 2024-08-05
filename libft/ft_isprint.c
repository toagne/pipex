/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:38:51 by mpellegr          #+#    #+#             */
/*   Updated: 2024/04/22 12:44:53 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int arg)
{
	if (arg >= 32 && arg <= 126)
		return (1);
	return (0);
}
/*
int  main(void)
{
	char c;

	c = 'g';
	printf("%d\n", isprint(c));
	printf("%d\n", ft_isprint(c));
}
*/
