/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 04:25:21 by alanter           #+#    #+#             */
/*   Updated: 2018/10/23 17:59:52 by alanter          ###   ########.fr       */
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

void	draw_back(unsigned int *img)
{
	int x;
	int y;

	x = -1;
	while (++x < WIN_W)
	{
		y = -1;
		while (++y < WIN_H)
		{
			if ((y < WIN_H / 7))
				img[y * WIN_W + x] = 0x27AEE3;
			else if (y >= WIN_H / 7 && y < WIN_H / 6)
				img[y * WIN_W + x] = 0x397628;
			else
			{
				img[y * WIN_W + x] = 0x5F472F;
				if (rand() % 42 == 0)
					img[y * WIN_W + x] = 0x5F5C58;
				else if (rand() % 142 == 0)
					img[y * WIN_W + x] = 0xB1ADA5;
			}
		}
	}
}

static void     fill_pixel(unsigned int *img, int x, int y)
{
	int big;

	big = 0;
	y += 30;
	x += 30;
	while (big < 8)
	{
		if (x < WIN_W && y + big < WIN_H && x >= 30 && y + big >= 30)
			img[y * WIN_W + (x + big)]= 0x442525;
		big++;
	}
	big = 0;
	while (big < 8)
	{
		if (x < WIN_W && y + big < WIN_H && x >= 30 && y + big >= 30)
			img[(y + big) * WIN_W + x]= 0x442525;
		big++;
	}
}

static void     draw_line(unsigned int *img, t_room a, t_room b)
{
	int ex;
	int ey;
	int err;
	int e;

	ex = abs(b.x - a.x);
	ey = abs(b.y - a.y);
	err = (ex > ey ? ex : -ey) / 2;
	while (a.x != b.x || a.y != b.y)
	{
		e = err;
		fill_pixel(img, a.x, a.y);
		if (e > -ex && (err -= ey) != 1e-9)
			a.x > b.x ? a.x-- : a.x++;
		if (e < ey && (err += ex) != 1e-9)
			a.y > b.y ? a.y-- : a.y++;
	}
	fill_pixel(img, a.x, a.y);
}

void	draw_room(unsigned int *img, int rx, int ry, int color)
{
	int s_x = 0;
	int s_y = 0;
	int x;
	int y;

	x = rx;
	while (++x < WIN_W)
	{
		y = ry;
		while (++y < WIN_H)
		{
			if (s_x < 70 && s_y < 70)
				img[y * WIN_W + x]= color; 
			if (s_x < 70 && s_y < 70 && rand() % 42 == 0)
				img[y * WIN_W + x] = 0x442525;
			s_y++;
		}
		s_y = 0;
		s_x++;
	}
}

static void	scale(t_info *info)
{
	t_room *tmp;

	tmp = info->room;
	info->xmin = 5000;
	info->ymin = 5000;
	info->xmax = 0;
	info->ymax = 0;
	while (tmp)
	{
		if (tmp->x < info->xmin)
			info->xmin = tmp->x;
		else if (tmp->x > info->xmax)
			info->xmax = tmp->x;
		if (tmp->y < info->ymin)
			info->ymin = tmp->y;
		else if (tmp->y > info->ymax)
			info->ymax = tmp->y;
		tmp = tmp->next;
	}
	if (info->xmax > 500 || info->ymax > 30)
	{
		printf("Error, map is too big\nWrong format for coordinates\n");
		exit(0);
	}
	info->xmax = (WIN_W - WIN_W /10) / (info->xmax - info->xmin);
	info->ymax = (WIN_H - WIN_H /4) / (info->ymax - info->ymin);
//	info->xmax = 1; 
//	info->ymax = 1; 
}
void	calc_coord(t_info *info)
{
	t_room *tmp;

	scale (info);
	tmp = info->room;
	while (tmp)
	{
		tmp->x = 100 + (tmp->x - info->xmin) * info->xmax * 5 / 8;
		tmp->y = 200 + ((tmp->y - info->ymin) * info->ymax / 2);
		tmp = tmp->next;
	}
}

void	draw_rooms(t_mlx *mlx, t_info *info)
{
	t_room *tmp;
	int i;

	tmp = info->room;
	i = 0;
	calc_coord(info);
	while (tmp)
	{
		while (tmp->links[i])
		{
			if (!tmp->links[i]->visited)
				draw_line(mlx->img.img, *tmp, *tmp->links[i]);
			i++;
		}
		if (tmp->start)
		draw_room(mlx->img.img, tmp->x, tmp->y, 0x8C5226);
		else if (tmp->end)
		draw_room(mlx->img.img, tmp->x, tmp->y, 0xBA966B);
		else
		draw_room(mlx->img.img, tmp->x, tmp->y, 0x230f0f);

		i = 0;
		tmp->visited = 1;
		tmp = tmp->next;
	}
}
