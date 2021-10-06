/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:45:09 by shenquin          #+#    #+#             */
/*   Updated: 2021/10/01 14:17:01 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen2(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_line(char *save)
{
	int	i;

	if (!save)
		return (-1);
	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
