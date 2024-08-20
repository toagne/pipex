/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pids.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:34:21 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/20 14:07:49 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exec(char *cmd, char **envp, char c)
{
	char	**cmd_arr;
	char	*path;

	cmd_arr = parse_cmd(cmd, c);
	path = create_path(cmd_arr, envp);
	if (execve(path, cmd_arr, envp) == -1)
		exit(1);
	free(path);
	ft_free(cmd_arr);
}

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

void	last_process(char *cmd, char **envp, char *output_file, int fd_in_file)
{
	int	fd_output_file;
	int	pid_2;

	open_output_file(output_file, &fd_output_file, 'n');
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
	close(fd_in_file);
	close(fd_output_file);
	return_status(pid_2);
}
