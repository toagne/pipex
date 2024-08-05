/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:14:43 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/05 16:21:23 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*dst_ptr;

	if (!dst && !src)
		return (dst);
	dst_ptr = dst;
	while (n--)
		*(unsigned char *)dst_ptr++ = *(unsigned char *)src++;
	return (dst);
}
/*
int main(void)
{
	char dst[] = "mandi";
	char src[] = "ciao";
	char dst1[] = "mandi";
	char src1[] = "ciao";
	memcpy(dst, src, sizeof(src));
	printf("%s\n", dst);
	ft_memcpy(dst1, src1, sizeof(src));
	printf("%s\n", dst1);
}
*/
