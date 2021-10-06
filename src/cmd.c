/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:49:33 by shenquin          #+#    #+#             */
/*   Updated: 2021/10/01 15:08:30 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	cmd_1(t_pipe *pipex)
{
	char	**cmd;
	char	*binary;

	cmd = ft_split(pipex->cmd1, ' ');
	if (cmd == NULL)
		exit_error("Split Error: split in command 1\n");
	binary = pathing(pipex, cmd[0]);
	pipex->pid_1 = fork();
	if (pipex->pid_1 == 0)
	{
		pipex->err_dup2 = dup2(pipex->infile, STDIN_FILENO);
		if (pipex->err_dup2 == -1)
			exit_error("Error dup2\n");
		pipex->err_dup2 = dup2(pipex->fd[1], STDOUT_FILENO);
		if (pipex->err_dup2 == -1)
			exit_error("Error dup2\n");
		execve(binary, cmd, pipex->envp);
		exit_error("Command 1 Error: execve failed\n");
	}
	norme_cmd1(pipex, cmd, binary);
	return (0);
}

int	cmd_2(t_pipe *pipex)
{
	char	**cmd;
	char	*binary;

	cmd = ft_split(pipex->cmd2, ' ');
	if (cmd == NULL)
		exit_error("Split Error: split in command 2\n");
	binary = pathing(pipex, cmd[0]);
	pipex->pid_2 = fork();
	if (pipex->pid_2 == 0)
	{
		pipex->err_dup2 = dup2(pipex->fd[0], STDIN_FILENO);
		if (pipex->err_dup2 == -1)
			exit_error("Error dup2\n");
		pipex->err_dup2 = dup2(pipex->outfile, STDOUT_FILENO);
		if (pipex->err_dup2 == -1)
			exit_error("Error dup2\n");
		execve(binary, cmd, pipex->envp);
		exit_error("Command 2 Error: execve failed\n");
	}
	norme_cmd2(pipex, cmd, binary);
	return (0);
}

void	norme_cmd2(t_pipe *pipex, char **cmd, char *binary)
{
	waitpid(pipex->pid_2, NULL, 0);
	close(pipex->outfile);
	close(pipex->fd[0]);
	pipex->fd[0] = -1;
	ft_free_split(cmd);
	free(binary);
}

void	norme_cmd1(t_pipe *pipex, char **cmd, char *binary)
{
	waitpid(pipex->pid_1, NULL, 0);
	close(pipex->infile);
	close(pipex->fd[1]);
	pipex->fd[1] = -1;
	ft_free_split(cmd);
	free(binary);
}
