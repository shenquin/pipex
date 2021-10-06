/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 13:02:32 by shenquin          #+#    #+#             */
/*   Updated: 2021/10/01 15:09:32 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft/inc/libft.h"

typedef struct s_pipe
{
	int		fd[2];
	int		infile;
	int		outfile;
	int		err_dup2;
	char	*cmd1;
	char	*cmd2;
	char	*path;
	char	**envp;
	pid_t	pid_1;
	pid_t	pid_2;
}			t_pipe;

int		open_w(char *av);
int		open_r(char *av);
int		cmd_1(t_pipe *pipex);
int		cmd_2(t_pipe *pipex);
void	norme_cmd1(t_pipe *pipex, char **cmd, char *binary);
void	norme_cmd2(t_pipe *pipex, char **cmd, char *binary);
char	*pathing(t_pipe *pipex, char *cmd_0);
char	*exit_error_2(t_pipe *pipex, char *s);

#endif
