/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:05:30 by shenquin          #+#    #+#             */
/*   Updated: 2021/10/01 14:47:43 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	open_w(char *av)
{
	int	fd;

	fd = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		exit_error("Outfile Error\n");
	return (fd);
}

int	open_r(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		exit_error("Infile Error\n");
	return (fd);
}
