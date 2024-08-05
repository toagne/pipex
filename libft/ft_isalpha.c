/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:27:08 by mpellegr          #+#    #+#             */
/*   Updated: 2024/04/22 11:40:49 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
int main(void)
{
	char c;
    c = 'Q';
    printf("uppercase isalpha: %d\n", isalpha(c));
	printf("uppercase ft_isalpha: %d\n", ft_isalpha(c));

    c = 'q';
    printf("lowercase isalpha: %d\n", isalpha(c));
	printf("lowercase ft_isalpha: %d\n", ft_isalpha(c));

    c='+';
    printf("non-alphabetic isalpha: %d\n", isalpha(c));
	printf("non-alphabetic ft_isalpha: %d\n", ft_isalpha(c));
}
*/
