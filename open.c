/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:21:05 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/15 15:40:49 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_input_file(char *input_file, int *fd_input_file)
{
	*fd_input_file = open(input_file, O_RDONLY);
	if (*fd_input_file == -1)
		error_no_file(input_file);
}

void	open_output_file(char *output_file, int *fd_output_file)
{
	*fd_output_file = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd_output_file == -1)
	{
		error_no_file(output_file);
		exit(1);
	}
}
