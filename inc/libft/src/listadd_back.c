/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listadd_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:45:09 by shenquin          #+#    #+#             */
/*   Updated: 2021/10/01 14:19:15 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*back;

	back = *alst;
	if (*alst)
	{
		while (back->next != NULL)
			back = back->next;
		back->next = new;
	}
	else
		*alst = new;
}
