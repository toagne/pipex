/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:18:38 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/05 16:54:51 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*str_ptr;
	size_t			n;
	size_t			tot_size;

	n = 0;
	tot_size = count * size;
	if (count && size && tot_size / count != size)
		return (NULL);
	str_ptr = (void *)malloc(tot_size);
	if (!str_ptr)
		return (NULL);
	ptr = (void *)str_ptr;
	while (n < count * size)
	{
		*str_ptr = '\0';
		str_ptr++;
		n++;
	}
	return (ptr);
}
/*
int main(void)
{
	char *s1 = calloc(5, sizeof(int));
	char *s2 = ft_calloc(5, sizeof(int));

	printf("%p\n", s1);
	printf("%p\n", s2);
	printf("%s\n", s1);
    printf("%s\n", s2);
}
*/
