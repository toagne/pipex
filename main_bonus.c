/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:16:11 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/20 14:59:24 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	usage_error(char **argv)
{
	ft_putstr_fd("Usage 1: ", STDERR_FILENO);
	ft_putstr_fd(argv[0], STDERR_FILENO);
	ft_putstr_fd(" <file1> <cmd1> <cmd2> ... <cmdn> <file2>\n", STDERR_FILENO);
	ft_putstr_fd("Usage 2: ", STDERR_FILENO);
	ft_putstr_fd(argv[0], STDERR_FILENO);
	ft_putstr_fd(" <here_doc> <LIMITER> <cmd1> <cmd2> <file>\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

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

int	main(int argc, char **argv, char **envp)
{
	int	fd_input_file;
	int	i;
	int	status;

	if (argc < 5)
		usage_error(argv);
	if (!ft_strncmp(argv[1], "here_doc", 8))
		here_doc(argc, argv, envp);
	else
	{
		input_check(argc, argv, envp);
		open_input_file(argv[1], &fd_input_file);
		i = 2;
		while (i < argc - 2)
		{
			pipex(argv[i], envp, &fd_input_file);
			i++;
		}
		last_process(argv[argc - 2], envp, argv[argc -1], fd_input_file);
	}
	while (wait(&status) > 0)
		;
}
