/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 09:34:00 by abiri             #+#    #+#             */
/*   Updated: 2018/11/15 15:20:40 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_lcount(char *filename)
{
	int		fd;
	int		res;
	int		result;
	char	buffer[1];

	result = 0;
	fd = open(filename, O_RDONLY);
	while ((res = read(fd, buffer, 1)) > 0)
	{
		if (buffer[0] == '\n')
			result++;
	}
	close(fd);
	if (res == -1)
	{
		ft_printf("%91@No such file as : %s%@\n", filename);
		exit(1);
	}
	if (result == 0)
	{
		ft_printf("%91@%s is an empty file !!%@\n", filename);
		exit(1);
	}
	return (result + 1);
}

t_link	**ft_fdf_parse(int *max_alt, char *filename)
{
	int		i;
	int		j;
	t_link	**linktab;
	char	***tab;
	char	*line;

	i = 0;
	j = open(filename, O_RDONLY);
	tab = ft_memalloc(sizeof(char*) * (ft_lcount(filename) + 1));
	while (get_next_line(j, &line) > 0)
		tab[i++] = ft_strsplit(line, ' ');
	close(j);
	linktab = ft_memalloc(sizeof(t_link *) * (i + 1));
	ft_fdf_filllink(tab, linktab);
	*max_alt = ft_fdf_linkpixels(linktab);
	return (linktab);
}

void	ft_keycheck(int key, t_all *all)
{
	if (key == 69 || key == 78)
		all->scale[0] += (key == 69) ? 1 : -1;
	else if (key == 124 || key == 123)
		all->offset[1] += (key == 124) ? 20 : -20;
	else if (key == 126 || key == 125)
		all->offset[0] += (key == 126) ? -20 : 20;
	else if (key == 75 || key == 67)
		all->scale[1] -= (key == 75) ? 0.5 : -0.5;
	else if (key == 116 || key == 121)
		all->scale[1] += (key == 116) ? 0.01 : -0.01;
	else if (key == 53)
	{
		mlx_destroy_window(all->win->m, all->win->w);
		exit(0);
	}
	else if (key == 47 || key == 43)
		all->teta += (key == 47) ? -0.1 : 0.1;
	else if (key == 3)
		all->fill = (all->fill == 0) ? 1 : 0;
	mlx_clear_window(all->win->m, all->win->w);
	ft_fdf_stats(all);
}

void	ft_putall_lines(t_all *all, t_link *temp, t_link *temp2, t_pix *axis)
{
	t_pix *copy;
	t_pix *copy1;

	copy = ft_newpix(all->scale[0] * (temp->self->x) + all->offset[0],
			all->scale[0] * (temp->self->y) + all->offset[1],
			all->scale[1] * -temp->self->z);
	ft_mlx_rotate(copy, all->teta, axis);
	copy1 = ft_newpix(all->scale[0] * (temp2->self->x) + all->offset[0],
			all->scale[0] * (temp2->self->y) + all->offset[1],
			all->scale[1] * -temp2->self->z);
	ft_mlx_rotate(copy1, all->teta, axis);
	ft_isoline(all->win, copy, copy1, all->max_alt * all->scale[1]);
	free(copy);
	free(copy1);
}

int		ft_fdf_putall(int key, void *content)
{
	t_link	*temp;
	t_all	*all;
	t_pix	*axis;
	int		i;

	i = -1;
	ft_keycheck(key, (all = (t_all*)content));
	ft_mlx_iso_rotate((axis = ft_newpix(WIDTH / 2, HEIGHT / 2, 0)));
	while ((temp = (all->tab)[++i]))
	{
		while (temp)
		{
			if (temp->down)
				ft_putall_lines(all, temp, temp->down, axis);
			if (temp->right)
			{
				ft_putall_lines(all, temp, temp->right, axis);
				if (temp->right->down && all->fill)
					ft_putall_lines(all, temp, temp->right->down, axis);
			}
			temp = temp->right;
		}
	}
	free(axis);
	return (0);
}
