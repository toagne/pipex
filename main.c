/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:16:11 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/09 14:16:46 by mpellegr         ###   ########.fr       */
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
		write(2, argv[0], ft_strlen(argv[0]));
		write(2, ": ", 2);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, ": ", 2);
		perror("");
		close(fd[1]);
		exit(EXIT_FAILURE);
	}
	if (dup2(input_file, 0) == -1)
	{
		perror("error duplicating file descriptor\n");
		close(input_file);
		close(fd[1]);
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
	ft_exec(argv[2], envp, argv);
}

void	parent_process(int *fd, char **argv, char **envp)
{
	int	output_file;

	close(fd[1]);
	output_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (output_file == -1)
	{
		write(2, argv[0], ft_strlen(argv[0]));
		write(2, ": ", 2);
		write(2, argv[4], ft_strlen(argv[4]));
		write(2, ": ", 2);
		perror("");
		close(fd[0]);
		exit(EXIT_FAILURE);
	}
	if (dup2(output_file, 1) == -1)
	{
		perror("error duplicating file descriptor\n");
		close(output_file);
		close(fd[0]);
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
	ft_exec(argv[3], envp, argv);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid_1;
	//pid_t	pid_2;

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
	pid_1 = fork();
	if (pid_1 == -1)
	{
		ft_putstr_fd("fork failed\n", STDERR_FILENO);
		return (2);
	}
	if (pid_1 == 0)
		child_process(fd, argv, envp);
	//if (ft_strncmp(argv[2], "sleep", 5) == 0)
	//	waitpid(0, NULL, 0);
	else
	{
//		pid_2 = fork();
//		if (pid_2 == -1)
//		{
//			perror("fork failed");
//			exit(EXIT_FAILURE);
//		}
//		if (pid_2 == 0)
			waitpid(pid_1, NULL, 0);
			parent_process(fd, argv, envp);
//		else
//		{
//			close(fd[0]);
//			close(fd[1]);
//			waitpid(pid_1, NULL, 0);
//			waitpid(pid_2, NULL, 0);
//		}
	}
}
