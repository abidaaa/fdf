/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:02:23 by aabouibr          #+#    #+#             */
/*   Updated: 2018/11/15 13:43:12 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_stats(t_all *all)
{
	mlx_string_put(all->win->m, all->win->w, 10, 110
			, ft_rgbint(183, 195, 243), "scale  : ");
	mlx_string_put(all->win->m, all->win->w, 100, 110
			, ft_rgbint(100, 94, 157),
			ft_itoa((int)all->scale[0]));
	mlx_string_put(all->win->m, all->win->w, 10, 130
			, ft_rgbint(183, 195, 243), "zscale : ");
	mlx_string_put(all->win->m, all->win->w, 100, 130
			, ft_rgbint(100, 94, 157),
			ft_itoa((int)(all->scale[1])));
	mlx_string_put(all->win->m, all->win->w, 10, 10, 0xffffff
			, "Navigation : UP,DOWN,LEFT,RIGHT");
	mlx_string_put(all->win->m, all->win->w, 10, 30, 0xffffff
			, "Zscale     : / and *");
	mlx_string_put(all->win->m, all->win->w, 10, 50, 0xffffff
			, "Zoom       : + and -");
	mlx_string_put(all->win->m, all->win->w, 10, 70, 0xffffff
			, "Fill       : f");
	mlx_string_put(all->win->m, all->win->w, 10, 90, ft_rgbint(239, 255, 250)
			, "------ Stats ------");
}
