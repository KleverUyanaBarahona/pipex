/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 19:00:42 by klever            #+#    #+#             */
/*   Updated: 2021/08/13 19:24:13 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	int		fd[2];

	check_argv(argc);
	pipe(fd);
	pid = fork();
	if (pid == -1)
		perror("Error");
	if (pid == 0)
		child_process_start(fd, argv, envp);
	else
	{
		pid = fork();
		if (pid == -1)
			perror("Error");
		if (pid == 0)
			child_process_end(fd, argv, envp);
		else
		{
			close(fd[FD_READ_END]);
			close(fd[FD_WRITE_END]);
		}
	}
	waitpid(pid, NULL, 0);
	return (0);
}