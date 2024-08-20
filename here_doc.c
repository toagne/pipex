/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:59:55 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/20 14:21:07 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	hd_last(char *cmd, char **envp, char *output_file, int fd_in_file)
{
	int	fd_output_file;
	int	pid_2;

	open_output_file(output_file, &fd_output_file, 'h');
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

static void	create_input(char **argv, int *fd_pipe)
{
	char	*str;

	write(1, "> ", 2);
	str = get_next_line(STDIN_FILENO);
	while (str && ft_strncmp(argv[2], str, ft_strlen(argv[2])))
	{
		if (write(fd_pipe[1], str, ft_strlen(str)) == -1)
		{
			ft_putstr_fd("write to pipe failed\n", STDERR_FILENO);
			close(fd_pipe[0]);
			close(fd_pipe[1]);
			free(str);
			exit(EXIT_FAILURE);
		}
		free(str);
		write(1, "> ", 2);
		str = get_next_line(STDIN_FILENO);
	}
	if (str)
		free(str);
}

void	here_doc(int argc, char **argv, char **envp)
{
	int		fd_pipe[2];
	int		fd_input_file;
	int		i;

	if (pipe(fd_pipe) == -1)
	{
		ft_putstr_fd("pipe failed\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	create_input(argv, fd_pipe);
	close(fd_pipe[1]);
	fd_input_file = fd_pipe[0];
	i = 3;
	while (i < argc -2)
	{
		pipex(argv[i], envp, &fd_input_file);
		i++;
	}
	hd_last(argv[argc - 2], envp, argv[argc - 1], fd_input_file);
}
