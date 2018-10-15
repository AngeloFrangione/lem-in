/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_comments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 12:22:34 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/14 12:22:42 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_iscomment(t_info *info)
{
	if (info->buff[0] == '#')
		return (TRUE);
	return (FALSE);
}

int		ft_iscommand(t_info *info)
{
	if (ft_strequ(info->buff, "##start"))
	{
		if (info->start == TRUE || info->start == 2)
			return (-1);
		info->start = TRUE;
		(!info->ants) ? ft_throw_error(E_START_BEFORE_ANT, info) : 0;
		return (TRUE);
	}
	else if (ft_strequ(info->buff, "##end"))
	{
		if (info->end == TRUE || info->end == 2)
			return (-1);
		info->end = TRUE;
		(!info->ants) ? ft_throw_error(E_END_BEFORE_ANT, info) : 0;
		return (TRUE);
	}
	else if (info->buff[0] == '#' && info->buff[1] == '#')
		return (TRUE);
	return (FALSE);
}