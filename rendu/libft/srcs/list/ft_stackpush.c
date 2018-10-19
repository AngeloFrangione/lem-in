/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angelo <angelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 23:41:45 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/19 02:27:21 by angelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackpush(t_stack **stack, void *content, size_t len)
{
	t_stack *new;

	new = ft_stacknew(content, len);
	ft_lstappend((t_list**)stack, (t_list*)new);
}
