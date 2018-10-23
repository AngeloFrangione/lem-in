/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:14:43 by alanter           #+#    #+#             */
/*   Updated: 2018/10/23 17:59:51 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		ft_new_image(t_mlx *mlx)
{
	if (mlx)
		;
//	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
//	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_W, WIN_H);
//	mlx->img.img = (unsigned int*)mlx_get_data_addr(mlx->img.img_ptr,
//			&(mlx->img.size_l), &(mlx->img.bpp), &(mlx->img.endian));
//	draw_back(mlx->img.img, mlx);
//	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
//	draw_str(mlx);
}

int			loop_sort(t_mlx *mlx)
{
	if (mlx)
		;
//	static int	i = 0;
//
//	if (i == 0 && (mlx->ok = get_next_line(0, &(mlx->stk.inst))) > 0)
//	{
//		mlx->nb_inst += 1;
//		inst(mlx->stk.inst, &(mlx->stk));
//		if (mlx->speed >= 50)
//		{
//			usleep(mlx->speed);
//			ft_new_image(mlx, mlx->stk, mlx->val_h);
//		}
//		else if (mlx->nb_inst % 5 == 0 || mlx->print_ok == 1)
//			ft_new_image(mlx, mlx->stk, mlx->val_h);
//	}
//	if (mlx->ok == 0 && (mlx->print_ok = 1))
//		ft_new_image(mlx, mlx->stk, mlx->val_h);
//	if (i == 0)
//		free(mlx->stk.inst);
//	if (mlx->stk.inst[0] == 0)
//		i = 1;
	return (0);
}

int			deal_key(int key, t_mlx *mlx)
{
	if (key && mlx)
		;
//	if (key == 46)
//	{
//		mlx->menu = (mlx->menu == 0) ? 1 : 0;
//		ft_new_image(mlx);
//	}
//	if (key == 124)
//	{
//		if (mlx->speed >= 50)
//			mlx->speed /= 10;
//		mlx_loop_hook(mlx->mlx_ptr, loop_sort, mlx);
//	}
//	if (key == 123)
//	{
//		if (mlx->speed < 500000)
//			mlx->speed *= 10;
//		mlx_loop_hook(mlx->mlx_ptr, loop_sort, mlx);
//	}
	if (key == 53)
		exit(0);
//	//else
//	//	colors(key, mlx);
	return (0);
}


void		*window(t_info *info)
{
	t_mlx	*mlx;

	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
//	mlx->speed = 500000;
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_W, WIN_H, "Lem-in");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_W, WIN_H);
	mlx->img.img = (unsigned int*)mlx_get_data_addr(mlx->img.img_ptr,
			&(mlx->img.size_l), &(mlx->img.bpp), &(mlx->img.endian));
//	//colorfull(mlx);
	draw_back(mlx->img.img);
	draw_rooms(mlx, info);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	//draw_str(mlx);
	mlx_key_hook(mlx->win, deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (mlx->mlx_ptr);
}
