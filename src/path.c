/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:11:20 by shenquin          #+#    #+#             */
/*   Updated: 2021/10/01 14:32:11 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static char	*parse_entire_path(char *cmd_0, char *directory)
{
	char	*path;
	char	*entire_path;

	if (directory[ft_strlen(directory) - 1] == '/')
		path = ft_strdup(directory);
	else
		path = ft_strjoin(directory, "/");
	if (path == NULL)
		exit_error("Entire path Error\n");
	entire_path = ft_strjoin(path, cmd_0);
	if (entire_path == NULL)
		exit_error("Entire path Error: Empty path\n");
	free(path);
	return (entire_path);
}

static char	*parse_path(t_pipe *pipex, char *cmd_0)
{
	size_t	index;
	char	**directories;
	char	*path;

	index = 0;
	directories = ft_split(pipex->path, ':');
	if (directories == NULL)
		exit_error("Split Error: Directories error\n");
	while (directories[index])
	{
		path = parse_entire_path(cmd_0, directories[index]);
		if (access(path, R_OK) != 0)
			free(path);
		else
		{
			ft_free_split(directories);
			return (path);
		}
		index++;
	}
	ft_free_split(directories);
	return (exit_error_2(pipex, "Path Error: Path does not exist\n"));
}

char	*pathing(t_pipe *pipex, char *cmd_0)
{
	char	*path;

	if (cmd_0[0] == '/' || cmd_0[0] == '.' || cmd_0[0] == '~')
	{
		path = ft_strdup(cmd_0);
		if (path == NULL)
			exit_error("Pathing Error : NULL path\n");
		return (path);
	}
	return (parse_path(pipex, cmd_0));
}
