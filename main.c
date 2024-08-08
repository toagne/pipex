/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:16:11 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/08 16:54:00 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	if (dup2(input_file, 0) == -1)
	{
		perror("error duplicating file descriptor\n");
		close(input_file);
		exit(EXIT_FAILURE);
	}
	close(input_file);
	if (dup2(fd[1], 1) == -1)
	{
		perror("error duplicating file descriptor\n");
		close(fd[1]);
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
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
	if (dup2(output_file, 1) == -1)
	{
		perror("error duplicating file descriptor\n");
		close(output_file);
		exit(EXIT_FAILURE);
	}
	close(output_file);
	if (dup2(fd[0], 0) == -1)
	{
		perror("error duplicating file descriptor\n");
		close(fd[0]);
		exit(EXIT_FAILURE);
	}
	close(fd[0]);
	ft_exec(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd("wrong input", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
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
