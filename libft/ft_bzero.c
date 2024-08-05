/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:06:25 by mpellegr          #+#    #+#             */
/*   Updated: 2024/04/22 13:14:18 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	void	*str_ptr;

	str_ptr = str;
	while (n--)
	{
		*(unsigned char *)str_ptr = '\0';
		str_ptr++;
	}
}
/*
int main(void)
{
	char str[20];
    char c = 'b';
    char str1[20];
    bzero(str, 5);
    ft_bzero(str1, 5);
}
*/
