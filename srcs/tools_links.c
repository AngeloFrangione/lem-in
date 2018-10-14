/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 16:50:04 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/14 16:50:13 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_islink(t_info *info)
{
	char	**split;
	int		i;

	if (ft_strchr(info->buff, ' '))
		return (0);
	split = ft_strsplit(info->buff, '-');
	i = 0;
	while (split[i])
		i++;
	if (i != 2)
	{
		free_charofchar(split);
		return (0);
	}
	
	free_charofchar(split);
	return (1);
}
