/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angelo <angelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 23:41:45 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/19 02:27:19 by angelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_stkpop(t_stack *stk)
{
	t_stack	*prev;

	if (!stk)
		return (NULL);
	while (stk->next)
	{
		prev = stk;
		stk = stk->next;
	}
	prev->next = NULL;
	return (stk);
}
