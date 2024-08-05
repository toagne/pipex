/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:45:35 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/05 16:22:12 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*dst_ptr;
	char	*src_ptr;

	if (!dst && !src)
		return (dst);
	if (dst == src)
		return (dst);
	dst_ptr = dst;
	src_ptr = (char *)src;
	if (dst > src)
	{
		while (len--)
			((char *)dst_ptr)[len] = src_ptr[len];
	}
	else
	{
		while (len--)
			*(char *)dst_ptr++ = *src_ptr++;
	}
	return (dst);
}
//line 26 - check for overlap
//line 29 - if yes i copy backword
//line 34 - if no overlap or destination is after source copy fo    rward
/*
int main(void)
{
	char dst[] = "mandi";
    char src[] = "ciao";
    char dst1[] = "mandi";
    char src1[] = "ciao";
    memmove(dst, src, sizeof(src));
    printf("%s\n", dst);
    ft_memmove(dst1, src1, sizeof(src));
    printf("%s\n", dst1);
}
*/
