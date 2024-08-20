/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:21:05 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/20 14:30:49 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_input_file(char *input_file, int *fd_input_file)
{
	*fd_input_file = open(input_file, O_RDONLY);
	if (*fd_input_file == -1)
	{
		if (access(input_file, F_OK) != 0)
			error_no_file(input_file);
		if (access(input_file, F_OK) == 0 && access(input_file, X_OK) != 0)
			error_no_permission(input_file);
	}
}

void	open_output_file(char *output_file, int *fd_out_file, char c)
{
	if (c == 'h')
		*fd_out_file = open(output_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		*fd_out_file = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd_out_file == -1)
	{
		if (access(output_file, F_OK) != 0)
			error_no_file(output_file);
		if (access(output_file, F_OK) == 0 && access(output_file, X_OK) != 0)
			error_no_permission(output_file);
		while (wait(NULL) > 0)
			;
		exit(1);
	}
}
