/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 16:49:36 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/14 20:46:25 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_isnumber(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '+')
			i++;
		else if (s[i] == '-')
			i++;
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	if (ft_strlen(s) > 11)
		return (0);
	else if (ft_atol(s) > INT_MAX || ft_atol(s) < INT_MIN)
		return (0);
	return (1);
}

int				check_room_duplicates(t_info *info, char *name)
{
	t_room *tmp;

	tmp = info->room;
	while (tmp)
	{
		if (ft_strequ(name, tmp->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int		ft_isvalid_room_name(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!ft_isprint(s[i]) || s[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void		ft_setstart(t_info *info)
{
	t_room *tmp;

	tmp = info->room;
	while (tmp->next)
		tmp = tmp->next;
	tmp->start = 1;
	info->start = 2;
}

void		ft_setend(t_info *info)
{
	t_room *tmp;

	tmp = info->room;
	while (tmp->next)
		tmp = tmp->next;
	tmp->end = 1;
	info->end = 2;
}



int				ft_isroom(t_info *info)
{
	char	**split;
	int		i;

	split = ft_strsplit(info->buff, ' ');
	i = 0;
	while (split[i])
		i++;
	if (i != 3)
	{
		free_charofchar(split);
		return (0);
	}
	if (!ft_isvalid_room_name(split[0]) || !ft_isnumber(split[1]) || \
		!ft_isnumber(split[2]))
	{
		free_charofchar(split);
		return (0);
	}
	if (check_room_duplicates(info, split[0]))
		return (0);
	add_room(&info->room, ft_strdup(split[0]));
	(info->start == 1) ? ft_setstart(info) : 0;
	(info->end == 1) ? ft_setend(info) : 0;
	free_charofchar(split);
	return (1);
}
