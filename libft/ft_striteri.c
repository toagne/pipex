/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:34:29 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/02 18:10:42 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		n;

	if (s && f)
	{
		n = 0;
		while (*s)
		{
			f(n, s);
			n++;
			s++;
		}
	}
}
/*
void ft_f(unsigned int n, char *c)
{
	c = c +	n;
}

int main(void)
{
	char *s = (void *)0;
	ft_striteri(s, ft_f);
	printf("%s\n", s);
}
*/
