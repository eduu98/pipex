/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:16:00 by ecruz-go          #+#    #+#             */
/*   Updated: 2022/01/17 12:50:56 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* Child process that create a fork and a pipe, put the output inside a pipe
 and then close with the exec function. The main process will change his stdin
 for the pipe file descriptor. */
void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		p[2];

	if (pipe(p) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(p[READ_END]);
		dup2(p[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(p[WRITE_END]);
		dup2(p[READ_END], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

/* Function who make a child process that will read from the stdin with
 get_next_line until it find the limiter word and then put the output inside a
 pipe. The main process will change his stdin for the pipe file descriptor. */
void	here_doc(char *limiter, int argc)
{
	pid_t	reader;
	int		p[2];
	char	*line;

	if (argc < 6)
		arg_error(1);
	if (pipe(p) == -1)
		error();
	reader = fork();
	if (reader == 0)
	{
		close(p[READ_END]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(p[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(p[WRITE_END]);
		dup2(p[READ_END], STDIN_FILENO);
		wait(NULL);
	}
}

/* Main function that run the childs process with the right file descriptor
 or display an error message if arguments are wrong. It will run here_doc
 function if the "here_doc" string is find in argv[1] */
int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	filein;
	int	fileout;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			fileout = open_file(argv[argc - 1], 0);
			here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			fileout = open_file(argv[argc - 1], 1);
			filein = open_file(argv[1], 2);
			dup2(filein, STDIN_FILENO);
		}
		while (i < argc - 2)
			child_process(argv[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		execute(argv[argc - 2], envp);
	}
	arg_error(1);
}
