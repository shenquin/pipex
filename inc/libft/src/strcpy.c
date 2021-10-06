/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:45:09 by shenquin          #+#    #+#             */
/*   Updated: 2021/10/01 14:22:18 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (0);
	while (src[i] && i)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
