/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 08:57:22 by alanter           #+#    #+#             */
/*   Updated: 2018/10/24 08:58:32 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	menu(t_mlx *mlx, int c)
{
	if (mlx->menu == 0)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W - 120, 5, c, "M   : Menu");
	if (mlx->menu == 1)
	{
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 5, c, "M   : Close");
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 25, c, "->  : Speed up");
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 45, c, "<-  : Speed down");
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 65, c, "1   : Colorfull");
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 85, c, "2   : Black&white");
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 105, c, "3   : Random");
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 125, c, "4   : Negative");
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 145, c, "Esc : Quit");
	}
}

void	draw_str(t_mlx *mlx)
{
	int		c;
	char	*nb_i;

	c = 0x000040;
	nb_i = ft_itoa(mlx->nb_inst);
	mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W - 70, WIN_H - 30, c, nb_i);
	free(nb_i);
	if (mlx->speed < 5)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X100000");
	else if (mlx->speed < 50)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X10000");
	else if (mlx->speed < 500)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X1000");
	else if (mlx->speed < 5000)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X100");
	else if (mlx->speed < 50000)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X10");
	else if (mlx->speed < 500000)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X1");
	else if (mlx->speed < 5000000)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X0.1");
	menu(mlx, c);
}
