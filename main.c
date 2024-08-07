/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:16:11 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/07 16:44:59 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	*find_path(char *cmd, char **envp)
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
			return (path);
		free(path);
		i++;
	}
	ft_free(paths);
	return (NULL);
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
		//perror("command not found: cmd_arr[0]");
		ft_free(cmd_arr);
		exit(EXIT_FAILURE);
	}
}

void	child_process(int *fd, char **argv, char **envp)
{
	int	input_file;

	close(fd[0]);
	input_file = open(argv[1], O_RDONLY, 0777);
	if (input_file == -1)
	{
		perror("error opening\n");
		exit(EXIT_FAILURE);
	}
	if(dup2(input_file, 0) == -1) // file opened will be input/read
	{
		perror("error duplicating file descriptor\n");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[1], 1) == -1) // fd[1] will be write/output
	{
		perror("error duplicating file descriptor\n");
		exit(EXIT_FAILURE);
	}
	ft_exec(argv[2], envp);
}

void	parent_process(int *fd, char **argv, char **envp)
{
	int	output_file;

	close(fd[1]);
	output_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (output_file == -1)
	{
		perror("error opening\n");
		exit(EXIT_FAILURE);
	}
	if(dup2(output_file, 1) == -1) // file opened will be output/write
	{
		perror("error duplicating file descriptor\n");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[0], 0) == -1) // fd[0] will be read/input
	{
		perror("error duplicating file descriptor\n");
		exit(EXIT_FAILURE);
	}
	ft_exec(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
		{
			ft_putstr_fd("pipe failed\n", STDERR_FILENO);
			return (1);
		}
		pid = fork();
		if (pid == -1)
		{
			ft_putstr_fd("fork failed\n", STDERR_FILENO);
			return (2);
		}
		if (pid == 0)
			child_process(fd, argv, envp);
		if (ft_strncmp(argv[2], "sleep", 5) == 0)
			waitpid(0, NULL, 0);
		parent_process(fd, argv, envp);
	}
	else
	{
		ft_putstr_fd("wrong input", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
