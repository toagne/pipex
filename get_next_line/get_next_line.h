/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:14:59 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/20 12:19:52 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_strchr_with_prot(const char *str, int c);
size_t	ft_lengnl(char *str);
char	*create_buffer(char *buffer, char *fake_buffer);
char	*n_f(char *str1, char *str2);
char	*pop_bufer(char *new_str, char *s1, char *s2);

#endif
