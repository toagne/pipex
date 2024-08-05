/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:51:00 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/07 09:59:36 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	void	*str_ptr;

	str_ptr = str;
	while (n--)
	{
		*(unsigned char *)str_ptr = (unsigned char) c;
		str_ptr++;
	}
	return (str);
}
/*
#include <string.h>
#include <stdio.h>

int main(void)
{
	char str[20];
	char c = 'b';
	char str1[20];
	memset(str, c, 5);
	printf("%s\n", str);
	ft_memset(str1, c, 5);
	printf("%s\n", str1); 
}
*/
