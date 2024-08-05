/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:20:48 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/03 09:48:59 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*src_ptr;

	if (dstsize <= 0)
		return (ft_strlen(src));
	src_ptr = (char *)src;
	while ((dstsize--) - 1 && *src_ptr)
		*dst++ = *src_ptr++;
	*dst = '\0';
	return (ft_strlen(src));
}
/*
int main(void)
{
	char dst[30];
	char src[] = "lorem ipsum dolor sit amet";
	char dst1[30];
	char src1[] = "lorem ipsum dolor sit amet";
	printf("%lu\n", strlcpy(dst, src, 0));
	printf("%s\n", dst);
	printf("%zu\n", ft_strlcpy(dst1, src1, 0));
	printf("%s\n", dst1);
}
*/
