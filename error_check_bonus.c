/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:46:23 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/19 16:35:23 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	no_files(int argc, char **argv)
{
	if (argc == 5 && argv[1][0] == '\0' && argv[argc - 1][0] == '\0')
	{
		error_no_file(argv[1]);
		error_no_file(argv[argc - 1]);
		exit(1);
	}
}

static void	no_files_more_cmd(int argc, char **argv, char **envp)
{
	int	i;
	int	fd_in_file;

	if (argc > 5 && argv[1][0] == '\0' && argv[argc - 1][0] == '\0')
	{
		error_no_file(argv[1]);
		error_no_file(argv[argc - 1]);
		fd_in_file = open("/dev/null", O_RDONLY);
		i = 3;
		while (i < argc - 2)
		{
			pipex(argv[i], envp, &fd_in_file);
			i++;
		}
		last_process(argv[argc - 3], envp, "/dev/null", fd_in_file);
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
	int	i;

	if (argv[1][0] == '\0')
	{
		error_no_file(argv[1]);
		fd_in_file = open("/dev/null", O_RDONLY);
		if (fd_in_file == -1)
			exit (EXIT_FAILURE);
		i = 3;
		while (i < argc - 2)
		{
			pipex(argv[i], envp, &fd_in_file);
			i++;
		}
		last_process(argv[argc - 2], envp, argv[argc - 1], fd_in_file);
		close(fd_in_file);
		exit(0);
	}
}

void	input_check(int argc, char **argv, char **envp)
{
	no_files(argc, argv);
	no_files_more_cmd(argc, argv, envp);
	no_output_file(argc, argv);
	no_input_file(argc, argv, envp);
}
