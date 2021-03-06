/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:02:10 by shenquin          #+#    #+#             */
/*   Updated: 2021/10/01 15:15:01 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*exit_error_2(t_pipe *pipex, char *s)
{
	ft_putstr_fd(s, 0);
	if (pipex->infile > 0)
		close(pipex->infile);
	if (pipex->outfile > 0)
		close(pipex->outfile);
	if (pipex->fd[0] > 0)
		close(pipex->fd[0]);
	if (pipex->fd[1] > 0)
		close(pipex->fd[1]);
	exit(EXIT_FAILURE);
}

static char	*path(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			return (ft_substr(envp[i], 5, ft_strlen(envp[i])));
		}
		i++;
	}
	exit_error("Env error: PATH environement is not defined\n");
	return (NULL);
}

static t_pipe	fill_str(char **av, char **envp)
{
	t_pipe		pipex;

	ft_memset(&pipex, 0, sizeof(pipex));
	pipex.infile = open_r(av[1]);
	pipex.outfile = open_w(av[4]);
	pipex.cmd1 = av[2];
	pipex.cmd2 = av[3];
	pipex.path = path(envp);
	if (pipex.path == NULL)
		exit_error("Path error: no path\n");
	pipex.envp = envp;
	return (pipex);
}

int	main(int ac, char **av, char **envp)
{
	t_pipe	pipex;

	if (ac != 5)
		exit_error("Arg Error: Too many or too few arguments\n");
	if (ft_strlen(av[2]) == 0)
		exit_error("Arg Error: No first argument\n");
	if (ft_strlen(av[3]) == 0)
		exit_error("Arg Error: No second argument\n");
	pipex = fill_str(av, envp);
	if (pipe(pipex.fd) == -1)
		exit_error("Pipe fd error\n");
	cmd_1(&pipex);
	cmd_2(&pipex);
	free(pipex.path);
}
