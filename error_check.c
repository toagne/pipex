/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:46:23 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/15 16:38:24 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_check(int argc, char **argv, char **envp, int *fd_input_file)
{
	if (argc != 5)
	{
		ft_putstr_fd("wrong input", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (argv[1][0] == '\0' && argv[argc - 1][0] == '\0')
	{
		error_no_file(argv[1]);
		error_no_file(argv[argc - 1]);
		exit(1);
	}
	if (argv[argc -1] == NULL || argv[argc -1][0] == '\0')
	{
		write(2, "pipex: : No such file or directory\n", 35);
		exit(1);
	}
	if (argv[1][0] == '\0')
	{
		error_no_file(argv[1]);
		*fd_input_file = open("/dev/null", O_RDONLY);
		if (*fd_input_file == -1)
			exit (EXIT_FAILURE);
		last_process(argv[argc - 2], envp, argv[argc - 1], *fd_input_file);
		close(*fd_input_file);
		exit(0);
	}
}

void	error_fork_1(pid_t pid_1, int *fd_pipe, int *fd_input_file)
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
