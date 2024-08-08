/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:22:17 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/08 16:45:35 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_free(char **arr)
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

static char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*temp_path;
	char	*path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		temp_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (!path)
		{
			ft_free(paths);
			return (NULL);
		}
		if (access(path, F_OK) == 0)
		{
			ft_free(paths);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free(paths);
	return (cmd);
}

void	ft_exec(char *cmd, char **envp)
{
	char	**cmd_arr;
	char	*path;

	cmd_arr = ft_split(cmd, ' ');
	path = find_path(cmd_arr[0], envp);
	if (!path)
	{
		perror("command not found\n");
		ft_free(cmd_arr);
		exit(127);
	}
	if (execve(path, cmd_arr, envp) == -1)
	{
		if (access(path, X_OK) != 0 && access(path, F_OK) == 0)
		{
			if (ft_strncmp(path, cmd, ft_strlen(cmd)))
				free(path);
			ft_free(cmd_arr);
			perror("not access");
			exit(126);
		}
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(cmd_arr[0], 2);
		perror("\n");
		if (ft_strncmp(path, cmd, ft_strlen(cmd)))
			free(path);
		ft_free(cmd_arr);
		exit(127);
	}
	free(path);
	ft_free(cmd_arr);
}
