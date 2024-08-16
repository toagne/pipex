/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:16:11 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/16 16:01:08 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	error_fork_1(pid_t pid_1, int *fd_pipe, int *fd_input_file)
{
	if (pid_1 == -1)
	{
		ft_putstr_fd("fork failed\n", STDERR_FILENO);
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		close(*fd_input_file);
		exit(EXIT_FAILURE);
	}
}

static void	pipex(char *cmd, char **envp, int *fd_input_file, pid_t *pid_1)
{
	int		fd_pipe[2];
//	pid_t	pid_1;

	if (pipe(fd_pipe) == -1)
	{
		ft_putstr_fd("pipe failed\n", STDERR_FILENO);
		close(*fd_input_file);
		exit(EXIT_FAILURE);
	}
	*pid_1 = fork();
	error_fork_1(*pid_1, fd_pipe, fd_input_file);
	if (*pid_1 == 0)
	{
		close(fd_pipe[0]);
		child_process(*fd_input_file, fd_pipe[1], cmd, envp);
	}
	close(fd_pipe[1]);
	close(*fd_input_file);
	*fd_input_file = fd_pipe[0];
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_input_file;
	int		i;
	int		pid;
	int		status;

	wrong_or_no_input(argc, argv, envp);
	open_input_file(argv[1], &fd_input_file);
	i = 2;
	pipex(argv[i], envp, &fd_input_file, &pid);
	last_process(argv[argc - 2], envp, argv[argc -1], fd_input_file);
	if (waitpid(pid, &status, 0) == -1)
		perror("waitpid failed for child 2");
	if (WIFSIGNALED(status))
	{
		write(2, "Segmentation fault in child 1\n", 30);
		exit(128 + WTERMSIG(status));
	}
	//wait(NULL);
}
