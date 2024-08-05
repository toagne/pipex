/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:54:01 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/07 10:09:31 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*src_ptr;
	size_t	dst_len;
	size_t	src_len;
	size_t	tot_len;

	if ((!dst && dstsize == 0) || (!src && dstsize == 0))
		return ('\0');
	dst_len = ft_strlen(dst);
	src_ptr = (char *)src;
	src_len = ft_strlen(src_ptr);
	tot_len = dst_len + src_len;
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	while (*src && dst_len < dstsize -1)
		dst[dst_len++] = *src++;
	dst[dst_len] = '\0';
	return (tot_len);
}
/*
int main(void)
{
	char dst[30] = "";
    char src[] = "123";
    char dst1[30] = "";
    char src1[] = "123";
    printf("%lu\n", strlcat(dst, src, 0));
    printf("%s\n", dst);
    printf("%zu\n", ft_strlcat(dst1, src1, 0));
    printf("%s\n", dst1);
}
*/
