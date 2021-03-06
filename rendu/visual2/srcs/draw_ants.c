/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 22:23:48 by alanter           #+#    #+#             */
/*   Updated: 2018/10/25 03:02:48 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		move_ants(t_info *info)
{
	t_room *tmp;

	tmp = info->room;
	while (tmp->end != 1)
		tmp = tmp->next;
	if (tmp->end == 1 && tmp->ant == info->ants)
		info->done = 1;
	while (tmp->start != 1)
	{
		if (tmp->previous_room->ant)
		{
			if (tmp->previous_room->start == 1)
			{
				tmp->ant = info->ants - tmp->previous_room->ant + 1;
				tmp->previous_room->ant -= 1;
			}
			else
			{
				tmp->ant = tmp->previous_room->ant;
				tmp->previous_room->ant = 0;
			}
		}
		tmp = tmp->previous_room;
	}
}

static void	print_name(t_mlx *mlx, t_room *tmp, int c)
{
	if (tmp->start == 1)
		mlx_string_put(mlx->mlx_ptr, mlx->win, tmp->x + 10,
				tmp->y + 35, 0x000000, "start");
	if (tmp->end == 1)
		mlx_string_put(mlx->mlx_ptr, mlx->win, tmp->x + 18,
				tmp->y + 35, 0x000000, "end");
	mlx_string_put(mlx->mlx_ptr, mlx->win, tmp->x, tmp->y - 2, c, tmp->name);
}

void		draw_ants(t_mlx *mlx, t_info *info)
{
	t_room *tmp;

	tmp = info->room;
	while (tmp)
	{
		tmp->white = 0;
		if (tmp->ant)
		{
			mlx_string_put(mlx->mlx_ptr, mlx->win, tmp->x + 29,
					tmp->y + 18, 0x000000, ft_itoa(tmp->ant));
			if (tmp->start != 1 && tmp->end != 1)
			{
				mlx_string_put(mlx->mlx_ptr, mlx->win, tmp->x + 15,
						tmp->y + 18, 0x000000, "L");
				mlx_string_put(mlx->mlx_ptr, mlx->win, tmp->x + 15,
						tmp->y + 38, 0x000000, ">o{-{");
			}
			tmp->white = 1;
			print_name(mlx, tmp, 0xFFFFFF);
		}
		if (tmp->white == 0)
			print_name(mlx, tmp, 0x000000);
		tmp = tmp->next;
	}
}
