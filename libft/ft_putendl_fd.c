/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:26:13 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/02 18:17:06 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write (fd, s, 1);
			s++;
		}
		write (fd, "\n", 1);
	}
}
/*
int main(void)
{
	char *str = NULL;
	int fd = 1;
	ft_putendl_fd(str, fd);
}
*/
