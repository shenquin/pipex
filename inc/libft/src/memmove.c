/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:45:09 by shenquin          #+#    #+#             */
/*   Updated: 2021/10/01 14:21:45 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove( void *dest, const void *src, size_t n)
{
	if (src < dest)
		while (n--)
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
