/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 14:59:13 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/14 16:48:40 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_search_ants(t_info *info)
{
	while (get_next_line(0, &info->buff))
	{
		ft_saveline(info);
		if (ft_isant_number(info))
			break ;
		else if (ft_iscommand(info) || ft_iscomment(info) > 0)
			continue ;
		else
			ft_throw_error(E_WRONG_ANT_NUMBER, info);
	}
	info->ants = ft_isant_number(info);
	(!info->ants) ? ft_throw_error(E_WRONG_ANT_NUMBER, info) : 0;
	ft_strdel(&info->buff);
}

void	ft_search_link(t_info *info)
{
	if (info->buff)
	{
		if (!ft_islink(info))
			ft_throw_error(0, info);
		ft_saveline(info);
		ft_strdel(&info->buff);
	}
	while (get_next_line(0, &info->buff))
	{
		if (ft_islink(info))
		{
			ft_saveline(info);
			ft_strdel(&info->buff);
			continue ;
		}
		else if (ft_iscommand(info) > 0 && ft_iscomment(info))
		{
			ft_saveline(info);
			continue ;
		}
		else
			break ;
	}
	ft_strdel(&info->buff);
}

void	ft_search_rooms(t_info *info)
{
	while (get_next_line(0, &info->buff))
	{
		if (ft_isroom(info))
		{
			ft_saveline(info);
			ft_strdel(&info->buff);
			continue ;
		}
		else if (ft_iscommand(info) > 0 && ft_iscomment(info))
		{
			ft_saveline(info);
			continue ;
		}
		else
			break ;
	}
}
