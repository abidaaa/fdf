/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:35:53 by abiri             #+#    #+#             */
/*   Updated: 2018/11/15 15:11:47 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_d_s(int s[2], int d[2], t_pix *p0, t_pix *p1)
{
	d[0] = abs(p1->x - p0->x);
	s[0] = p0->x < p1->x ? 1 : -1;
	d[1] = abs(p1->y - p0->y);
	s[1] = p0->y < p1->y ? 1 : -1;
}

void	ft_mlx_line(t_window *win, t_pix *p0, t_pix *p1, int color)
{
	int	s[2];
	int d[2];
	int err;
	int e2;

	get_d_s(s, d, p0, p1);
	err = (d[0] > d[1] ? d[0] : -d[1]) / 2;
	while (1)
	{
		mlx_pixel_put(win->m, win->w, p0->x, p0->y, color);
		if (p0->x == p1->x && p0->y == p1->y)
			break ;
		e2 = err;
		if (e2 > -d[0])
		{
			err -= d[1];
			p0->x += s[0];
		}
		if (e2 < d[1])
		{
			err += d[0];
			p0->y += s[1];
		}
	}
}

float	ft_map(float value, float max1, float max2)
{
	float ratio;

	ratio = (max2) / (max1);
	return (value * ratio);
}
