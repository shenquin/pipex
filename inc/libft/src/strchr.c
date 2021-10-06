/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:45:09 by shenquin          #+#    #+#             */
/*   Updated: 2021/10/01 14:22:12 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
		if (!*str++)
			return (0);
	return ((char *)str);
}
