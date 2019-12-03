/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:19:50 by aabouibr          #+#    #+#             */
/*   Updated: 2018/11/15 15:04:09 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_rotate(t_pix *point, float teta, t_pix *axis)
{
	float	tempx;

	tempx = point->x;
	point->x = axis->x + (point->x - axis->x) *
		cos(teta) - (point->y - axis->y) * sin(teta);
	point->y = axis->y + (point->y - axis->y) *
		cos(teta) + (tempx - axis->x) * sin(teta);
}

void	ft_mlxz_rotate(t_pix *point, float teta)
{
	float	tempx;
	t_pix	*axis;

	axis = ft_newpix(HEIGHT / 2, WIDTH / 2, 0);
	tempx = point->x;
	point->z = axis->z + (point->z - axis->z) *
		cos(teta) - (point->z - axis->z) * sin(teta);
	point->y = axis->y + (point->y - axis->y) *
		cos(teta) + (tempx - axis->x) * sin(teta);
	free(axis);
}
