/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:44:32 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/15 16:41:51 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path(char **cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*temp_path;
	char	*path;

	if (envp == NULL)
	{
		error_no_file(*cmd);
		ft_free(cmd);
		exit(127);
	}
	if (access(*cmd, F_OK) == 0 && access(*cmd, X_OK) == 0 && open(*cmd, O_DIRECTORY) == -1)
		return (ft_strdup(*cmd));
	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (envp[i] == NULL)
	{
		error_no_file(*cmd);
		ft_free(cmd);
		exit(127);
	}
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		temp_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp_path, *cmd);
		free(temp_path);
		if (!path)
		{
			ft_free(paths);
			return (NULL);
		}
		if ((access(path, F_OK) == 0 && access(path, X_OK) == 0) && open(*cmd, O_DIRECTORY) == -1)
		{
			ft_free(paths);
			return (path);
		}
		if (access(path, F_OK) == 0 && access(path, X_OK) != 0)
		{
			error_no_permission(path);
			free(path);
			ft_free(paths);
			ft_free(cmd);
			exit(126);
		}
		free(path);
		i++;
	}
	ft_free(paths);
	if (*cmd[0] == '/')
		error_no_file(*cmd);
	else
		error_command_not_found(*cmd);
	ft_free(cmd);
	exit(127);
}

void	check_cmd(char **cmd, char c)
{
	int	fd;

	if (*cmd)
	{
		if (ft_strchr(*cmd, '/') != NULL)
		{
			fd = open(*cmd, O_DIRECTORY);
			if (fd != -1)
			{
				error_is_a_directory(*cmd);
				ft_free(cmd);
				if (c == 'c')
					exit(0);
				else
					exit(126);
			}
		}
	}
	else
	{
		write(2, "pipex: : command not found\n", 27);
		ft_free(cmd);
		exit(127);
	}
}

char	*extract_token(char **cmd_ptr)
{
	char	*token;
	int		in_quote;
	char	quote_char;
	char	buffer[1024];
	int		len;

	in_quote = 0;
	quote_char = '\0';
	len = 0;
	while (**cmd_ptr && **cmd_ptr == ' ')
		(*cmd_ptr)++;
	while (**cmd_ptr)
	{
		if (**cmd_ptr == '"' || **cmd_ptr == '\'' || **cmd_ptr == '\\')
		{
			if (in_quote && **cmd_ptr == quote_char)
			{
				in_quote = 0;
				quote_char = '\0';
			}
			else if (!in_quote)
			{
				in_quote = 1;
				quote_char = **cmd_ptr;
			}
			(*cmd_ptr)++;
			continue ;
		}
		if (!in_quote && **cmd_ptr == ' ' && *(*cmd_ptr - 1) != '\\')
			break ;
		buffer[len++] = **cmd_ptr;
		(*cmd_ptr)++;
	}
	if (len == 0)
		return (NULL);
	buffer[len] = '\0';
	token = ft_strdup(buffer);
	if (**cmd_ptr)
		(*cmd_ptr)++;
	return (token);
}

char	**parse_cmd(char *cmd, char c)
{
	char	**arr;
	char	*token;
	int		token_count;
	int		i;
	char	*cmd_ptr;

	token_count = 0;
	i = 0;
	cmd_ptr = cmd;
	while ((token = extract_token(&cmd_ptr)) != NULL)
	{
		token_count++;
		free(token);
	}
	arr = (char **)malloc(sizeof(char *) * (token_count + 1));
	if (!arr)
		return (NULL);
	cmd_ptr = cmd;
	while ((token = extract_token(&cmd_ptr)) != NULL)
	{
		arr[i++] = token;
	}
	arr[i] = NULL;
	free(token);
	check_cmd(arr, c);
	return (arr);
}

void	ft_exec(char *cmd, char **envp, char c)
{
	char	**cmd_arr;
	char	*path;

	cmd_arr = parse_cmd(cmd, c);
	path = find_path(cmd_arr, envp);
	if (execve(path, cmd_arr, envp) == -1)
		exit(1);
	free(path);
	ft_free(cmd_arr);
}
