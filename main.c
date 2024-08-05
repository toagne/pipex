/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:19:44 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/05 16:19:47 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*temp_path;
	char	*path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i], ':');
	i = 0;
	while (paths[i])
	{
		temp_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	while (i-- >= 0)
		free(paths[i]);
	free(paths);
	return (NULL);
}

void	ft_exec(char *cmd, char **envp)
{
	char	**cmd_arr;
	char	*path;
	int		i;

	i = -1;
	cmd_arr = ft_split(cmd, ' ');
	path = find_path(cmd_arr[0], envp);
	if (!path)
	{
		while (cmd_arr[++i])
			free(cmd_arr[i]);
		free(cmd_arr);
	}
	if (execve(path, cmd_arr, envp) == -1)
	{
		perror("execve failure\n");
		exit(EXIT_FAILURE);
	}
}

void	child_process(int *fd, char **argv, char **envp)
{
	int	file_1;

	close(fd[0]);
	file_1 = open(argv[1], O_RDONLY, 0777);
	if (file_1 == -1)
	{
		perror("error opening\n");
		exit(EXIT_FAILURE);
	}
	if(dup2(file_1, 0) == -1) // file opened will be input/read
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
	int	file_2;

	close(fd[1]);
	file_2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_2 == -1)
	{
		perror("error opening\n");
		exit(EXIT_FAILURE);
	}
	if(dup2(file_2, 1) == -1) // file opened will be input/read
	{
		perror("error duplicating file descriptor\n");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[0], 0) == -1) // fd[1] will be write/output
	{
		perror("error duplicating file descriptor\n");
		exit(EXIT_FAILURE);
	}
	ft_exec(argv[2], envp);
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
		waitpid(pid, NULL, 0);
		parent_process(fd, argv, envp);
	}
	else
		ft_putstr_fd("wrong input", STDERR_FILENO);
}
