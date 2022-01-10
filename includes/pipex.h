/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:22:17 by ecruz-go          #+#    #+#             */
/*   Updated: 2022/01/10 12:54:04 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../Libft/libft.h"

/* Variables for the pipes */
# define READ_END	0
# define WRITE_END	1

/* Mandatory functions */
void	arg_error(int bonus);
void	error(void);
int		open_file(char *argv, int i);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);

/* Bonus functions */
int		get_next_line(char **line);

#endif
