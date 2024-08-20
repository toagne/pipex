/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:22:08 by mpellegr          #+#    #+#             */
/*   Updated: 2024/08/20 14:09:23 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include "get_next_line/get_next_line.h"

char	*create_path(char **cmd, char **envp);

char	**parse_cmd(char *cmd, char c);

void	input_check(int argc, char **argv, char **envp);

void	child_process(int fd_in_file, int fd_out_pipe, char *cmd, char **envp);
void	last_process(char *cmd, char **envp, char *output_file, int fd_in_file);

void	ft_free(char **arr);
void	return_status(int pid);

void	open_input_file(char *input_file, int *fd_input_file);
void	open_output_file(char *output_file, int *fd_output_file, char c);

void	error_no_file(char *file);
void	error_no_permission(char *str);
void	error_command_not_found(char *cmd);
void	error_is_a_directory(char *str);

void	pipex(char *cmd, char **envp, int *fd_input_file);

void	here_doc(int argc, char **argv, char **envp);

void	last_child(int fd_in_file, int fd_out_pipe, char *cmd, char **envp);

#endif
