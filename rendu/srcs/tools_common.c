/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_common.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 12:28:55 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/14 12:52:55 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_saveline(t_info *info)
{
	int newsize;

	if (!info->file)
		info->file = ft_memalloc(sizeof(char) * (ft_strlen(info->buff) + 2));
	else
	{
		newsize = sizeof(char) * ft_strlen(info->file) + ft_strlen(info->buff);
		info->file = ft_realloc(info->file, newsize + sizeof(char) * 2);
	}
	ft_strcat(info->file, info->buff);
	ft_strcat(info->file, "\n");
}

void	free_charofchar(char **table)
{
	int i;

	i = 0;
	while (table[i])
	{
		ft_strdel(&table[i]);
		i++;
	}
	free(table);
	table = NULL;
}
