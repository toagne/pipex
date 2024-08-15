/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:22:17 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/15 16:02:31 by mpellegr         ###   ########.fr       */
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
		write(2, "Segmentation fault in child 2\n", 30);
		exit(128 + WTERMSIG(status));
	}
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
	{
		exit(WEXITSTATUS(status));
	}
}
