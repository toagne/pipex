/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:46:23 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/16 14:58:28 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	wrong_argc(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("wrong input", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

static void	no_files(int argc, char **argv)
{
	if (argv[1][0] == '\0' && argv[argc - 1][0] == '\0')
	{
		error_no_file(argv[1]);
		error_no_file(argv[argc - 1]);
		exit(1);
	}
}

static void	no_output_file(int argc, char **argv)
{
	if (argv[argc -1] == NULL || argv[argc -1][0] == '\0')
	{
		write(2, "pipex: : No such file or directory\n", 35);
		exit(1);
	}
}

static void	no_input_file(int argc, char **argv, char **envp)
{
	int	fd_in_file;

	if (argv[1][0] == '\0')
	{
		error_no_file(argv[1]);
		fd_in_file = open("/dev/null", O_RDONLY);
		if (fd_in_file == -1)
			exit (EXIT_FAILURE);
		last_process(argv[argc - 2], envp, argv[argc - 1], fd_in_file);
		close(fd_in_file);
		exit(0);
	}
}

void	wrong_or_no_input(int argc, char **argv, char **envp)
{
	wrong_argc(argc);
	no_files(argc, argv);
	no_output_file(argc, argv);
	no_input_file(argc, argv, envp);
}
