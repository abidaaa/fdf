/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixels.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:00:03 by aabouibr          #+#    #+#             */
/*   Updated: 2018/11/14 20:52:51 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pix	*ft_newpix(float x, float y, float z)
{
	t_pix *result;

	result = (t_pix *)malloc(sizeof(t_pix));
	result->x = x;
	result->y = y;
	result->z = z;
	return (result);
}

void	ft_setpix(t_pix *pixel, float x, float y, float z)
{
	pixel->x = x;
	pixel->y = y;
	pixel->z = z;
}

int		ft_rgbint(int r, int g, int b)
{
	char *color;

	color = ft_memalloc(4);
	color[0] = b;
	color[1] = g;
	color[2] = r;
	return (*((int *)color));
}
