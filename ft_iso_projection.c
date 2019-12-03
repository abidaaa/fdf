/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:51:05 by aabouibr          #+#    #+#             */
/*   Updated: 2018/11/15 15:09:53 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_isopixel(t_window *win, t_pix *pixel, int color)
{
	t_pix	*new;

	new = ft_newpix(pixel->x, pixel->y, pixel->z);
	ft_mlx_iso_rotate(new);
	mlx_pixel_put(win->m, win->w, new->x, new->y + pixel->z, color);
	free(new);
}

void	ft_mlx_iso_rotate(t_pix *point)
{
	float	tempx;
	t_pix	*axis;

	axis = ft_newpix(HEIGHT / 2, WIDTH / 2, 0);
	tempx = point->x;
	point->x = axis->x + (point->x - axis->x) * cos(-M_PI / 6)
		- (point->y - axis->y) * sin(-M_PI / 3);
	point->y = axis->y + (point->y - axis->y) * cos(-M_PI / 3)
		+ (tempx - axis->x) * sin(-M_PI / 6);
	ft_mlxz_rotate(point, M_PI);
	free(axis);
}

void	ft_isoline(t_window *win, t_pix *pt1, t_pix *pt2, int color)
{
	t_pix	*temp1;
	t_pix	*temp2;

	temp1 = ft_newpix(pt1->x, pt1->y, pt1->z);
	temp2 = ft_newpix(pt2->x, pt2->y, pt2->z);
	ft_mlx_iso_rotate(temp1);
	ft_mlx_iso_rotate(temp2);
	ft_setpix(temp1, temp1->x, temp1->y - temp1->z, 0);
	ft_setpix(temp2, temp2->x, temp2->y - temp2->z, 0);
	ft_mlx_line(win, temp1, temp2,
			ft_rgbint(150, 50 - ft_map(pt2->z, color, 205),
				150 - ft_map(pt1->z, color, 50)));
	free(temp1);
	free(temp2);
}
