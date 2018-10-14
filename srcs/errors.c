/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 12:01:54 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/14 12:05:39 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_throw_error(int error, t_info *info)
{
	ft_strdel(&info->file);
	ft_strdel(&info->buff);
	free(info);
	ft_putendl("Error");
	exit(error);
}
