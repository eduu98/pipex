/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:53:56 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/12/21 13:12:43 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* Child process that run inside a fork, take the filein, put the output inside
 a pipe and then close with the exec function */
void	child_process(char **argv, char **envp, int *fd)
{
	int		filein;
	
	close(fd[WRITE_END]);
	filein = open_file(argv[1], 2);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[READ_END]);
	execute(argv[2], envp);
}

/* Parent process that take the data from the pipe, change the output for the
 fileout and also close with the exec function */
void	parent_process(char **argv, char **envp, int *fd)
{
	int		fileout;

	close(fd[READ_END]);
	fileout = open_file(argv[4], 1);
	dup2(fd[READ_END], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[WRITE_END]);
	execute(argv[3], envp);
}

/* Main function that run the child and parent process or display an error
 message if arguments are wrong */
int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child_process(argv, envp, fd);
		waitpid(pid1, NULL, 0);
		parent_process(argv, envp, fd);
		// close(fd[READ_END]);
		// close(fd[WRITE_END]);
	}
	else
		arg_error(0);
	return (0);
}
