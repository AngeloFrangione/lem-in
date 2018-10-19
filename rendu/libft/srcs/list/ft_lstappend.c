/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angelo <angelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:38:21 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/19 02:26:11 by angelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*t;

	if (alst)
	{
		if (*alst)
		{
			t = *alst;
			while (t->next)
				t = t->next;
			t->next = new;
		}
		else
		{
			*alst = new;
		}
	}
}
