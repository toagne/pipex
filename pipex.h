/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:22:08 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/16 15:01:39 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>

char	*create_path(char **cmd, char **envp);

char	**parse_cmd(char *cmd, char c);

void	wrong_or_no_input(int argc, char **argv, char **envp);

void	child_process(int fd_in_file, int fd_out_pipe, char *cmd, char **envp);
void	last_process(char *cmd, char **envp, char *output_file, int fd_in_file);

void	ft_free(char **arr);
void	return_status(int pid);

void	open_input_file(char *input_file, int *fd_input_file);
void	open_output_file(char *output_file, int *fd_output_file);

void	error_no_file(char *file);
void	error_no_permission(char *str);
void	error_command_not_found(char *cmd);
void	error_is_a_directory(char *str);

#endif
