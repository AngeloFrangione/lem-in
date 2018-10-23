/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 12:01:54 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/17 16:30:01 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_throw_error(int error, t_info *info)
{
	ft_strdel(&info->file);
	ft_strdel(&info->buff);
	clean(info);
	free(info);
	ft_putendl_fd("Error", 2);
	if (error != 0)
		ft_putnbr_fd(error, 2);
	else
		ft_putnbr_fd(info->error_no_exit, 2);
	exit(error);
}

void	ft_throw_error_coc(int error, t_info *info)
{
//	free_charofchar(info->split);
	ft_throw_error(error, info);
}
