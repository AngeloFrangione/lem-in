/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 16:39:17 by alanter           #+#    #+#             */
/*   Updated: 2018/10/23 17:55:14 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "libft.h"
# include "lem_in.h"
# include <limits.h>
# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define WIN_W 1350
# define WIN_H 780

typedef struct	s_img
{
	void			*img_ptr;
	unsigned int	*img;
	int				size_l;
	int				bpp;
	int				endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
	int			speed;
	int			nb_inst;
	int			menu;
}				t_mlx;

void			*window(t_info *info);
void			draw_str(t_mlx *mlx);
void			draw_back(unsigned int *img);
void			draw_rooms(t_mlx *mlx, t_info *info);
void			colors(int key, t_mlx *mlx);
void			colorfull(t_mlx *mlx);
void			ft_new_image(t_mlx *mlx);

#endif
