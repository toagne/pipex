/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:53:43 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/16 15:10:34 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_permission_path(char *path, char **cmd, char **env_paths)
{
	if (access(path, F_OK) == 0 && access(path, X_OK) != 0)
	{
		error_no_permission(path);
		free(path);
		ft_free(env_paths);
		ft_free(cmd);
		exit(126);
	}
}

static void	path_not_found(char **env_paths, char **cmd)
{
	ft_free(env_paths);
	if (*cmd[0] == '/')
		error_no_file(*cmd);
	else
		error_command_not_found(*cmd);
	ft_free(cmd);
	exit(127);
}

static char	*add_cmd_to_path(char *env_path, char *cmd)
{
	char	*temp_path;
	char	*path;

	temp_path = ft_strjoin(env_path, "/");
	path = ft_strjoin(temp_path, cmd);
	free(temp_path);
	return (path);
}

static char	**find_path(char **envp, char **cmd)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (envp[i] == NULL)
	{
		error_no_file(*cmd);
		ft_free(cmd);
		exit(127);
	}
	return (ft_split(envp[i] + 5, ':'));
}

char	*create_path(char **cmd, char **envp)
{
	int		i;
	char	**env_paths;
	char	*path;

	if (access(*cmd, F_OK) == 0 && access(*cmd, X_OK) == 0
		&& open(*cmd, O_DIRECTORY) == -1)
		return (ft_strdup(*cmd));
	env_paths = find_path(envp, cmd);
	i = 0;
	while (env_paths[i])
	{
		path = add_cmd_to_path(env_paths[i], *cmd);
		if ((access(path, F_OK) == 0 && access(path, X_OK) == 0)
			&& open(*cmd, O_DIRECTORY) == -1)
		{
			ft_free(env_paths);
			return (path);
		}
		check_permission_path(path, cmd, env_paths);
		free(path);
		i++;
	}
	path_not_found(env_paths, cmd);
	return (NULL);
}
