/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:16:11 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/15 16:42:37 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int fd_in_file, int fd_out_pipe, char *cmd, char **envp)
{
	if (dup2(fd_in_file, 0) == -1)
	{
		close(fd_out_pipe);
		exit(EXIT_FAILURE);
	}
	close(fd_in_file);
	if (dup2(fd_out_pipe, 1) == -1)
	{
		perror("error duplicating file descriptor\n");
		close(fd_out_pipe);
		exit(EXIT_FAILURE);
	}
	close(fd_out_pipe);
	ft_exec(cmd, envp, 'c');
}

void	last_child(int fd_in_file, int fd_out_pipe, char *cmd, char **envp)
{
	if (dup2(fd_in_file, 0) == -1)
	{
		close(fd_out_pipe);
		exit(EXIT_FAILURE);
	}
	close(fd_in_file);
	if (dup2(fd_out_pipe, 1) == -1)
	{
		perror("error duplicating file descriptor\n");
		close(fd_out_pipe);
		exit(EXIT_FAILURE);
	}
	close(fd_out_pipe);
	ft_exec(cmd, envp, 'l');
}

void	pipex(char *cmd, char **envp, int *fd_input_file)
{
	int		fd_pipe[2];
	pid_t	pid_1;

	if (pipe(fd_pipe) == -1)
	{
		ft_putstr_fd("pipe failed\n", STDERR_FILENO);
		close(*fd_input_file);
		exit(EXIT_FAILURE);
	}
	pid_1 = fork();
	error_fork_1(pid_1, fd_pipe, fd_input_file);
	if (pid_1 == 0)
	{
		close(fd_pipe[0]);
		child_process(*fd_input_file, fd_pipe[1], cmd, envp);
	}
	close(fd_pipe[1]);
	close(*fd_input_file);
	*fd_input_file = fd_pipe[0];
}

void	last_process(char *cmd, char **envp, char *output_file, int fd_in_file)
{
	int	fd_output_file;
	int	pid_2;

	open_output_file(output_file, &fd_output_file);
	pid_2 = fork();
	if (pid_2 == -1)
	{
		ft_putstr_fd("fork failed\n", STDERR_FILENO);
		close(fd_in_file);
		close(fd_output_file);
		exit(EXIT_FAILURE);
	}
	if (pid_2 == 0)
		last_child(fd_in_file, fd_output_file, cmd, envp);
	return_status(pid_2);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_input_file;
	int		i;

	first_check(argc, argv, envp, &fd_input_file);
	open_input_file(argv[1], &fd_input_file);
	i = 2;
	pipex(argv[i], envp, &fd_input_file);
	last_process(argv[argc - 2], envp, argv[argc -1], fd_input_file);
	wait(NULL);
}
