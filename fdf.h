/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 09:38:09 by abiri             #+#    #+#             */
/*   Updated: 2018/11/15 15:04:10 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# define PI 3.1415927
# define HEIGHT 1080
# define WIDTH 1920

typedef struct		s_pix
{
	int				x;
	int				y;
	int				z;
}					t_pix;

typedef struct		s_link
{
	t_pix			*self;
	struct s_link	*right;
	struct s_link	*down;
}					t_link;

typedef struct		s_window
{
	void			*m;
	void			*w;
}					t_window;

typedef struct		s_all
{
	t_window		*win;
	t_link			**tab;
	float			teta;
	float			max_alt;
	float			scale[2];
	float			offset[2];
	int				fill;
}					t_all;

float				ft_map(float value, float max1, float max2);
int					ft_rgbint(int r, int g, int b);
t_pix				*ft_newpix(float x, float y, float z);
t_link				**ft_fdf_parse(int *max, char *filename);
void				ft_mlx_rotate(t_pix *point, float teta, t_pix *axis);
void				ft_mlx_iso_rotate(t_pix *point);
void				ft_mlx_isopixel(t_window *win, t_pix *pixel, int color);
void				ft_setpix(t_pix *pixel, float x, float y, float z);
int					ft_fdf_putall(int key, void *content);
void				ft_mlxz_rotate(t_pix *point, float teta);
void				ft_isoline(t_window *win, t_pix *pt1
		, t_pix *pt2, int color);
void				ft_mlx_line(t_window *win, t_pix *p1, t_pix *p2, int color);
t_link				*ft_fdf_newlink(float x, float y, float z);
void				ft_fdf_linkadd(t_link *start, t_link *node);
int					ft_fdf_linkpixels(t_link **linktab);
void				ft_fdf_filllink(char ***tab, t_link **linktab);
void				ft_fdf_stats(t_all *all);
#endif
