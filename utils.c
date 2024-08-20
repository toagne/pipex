/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:22:17 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/19 11:58:29 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <string.h>

void	ft_free(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	return_status(int pid)
{
	int	status;

	if (waitpid(pid, &status, 0) == -1)
	{
		perror("waitpid failed for child 2");
		exit(EXIT_FAILURE);
	}
	if (WIFSIGNALED(status))
	{
		write(2, "Segmentation fault\n", 18);
		exit(128 + WTERMSIG(status));
	}
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
	{
		exit(WEXITSTATUS(status));
	}
}
