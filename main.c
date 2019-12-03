/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:05:14 by abiri             #+#    #+#             */
/*   Updated: 2019/12/03 17:53:43 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_fdf_init(t_all *all, t_link **tab)
{
	all->win->m = mlx_init();
	all->win->w = mlx_new_window(all->win->m, WIDTH, HEIGHT, "- FDF -");
	all->tab = tab;
	all->teta = 0;
	all->scale[0] = 20;
	all->scale[1] = 5;
	all->offset[0] = 100;
	all->offset[1] = 1000;
	all->fill = 0;
}

int			main(int argc, char **argv)
{
	int		max_alt;
	t_link	**tab;
	t_all	*all;

	if (argc != 2)
	{
		ft_printf("%93@Usage: ./fdf <filename>%@\n");
		return (1);
	}
	max_alt = 0;
	all = (t_all *)malloc(sizeof(t_all));
	all->win = (t_window *)malloc(sizeof(t_window));
	tab = ft_fdf_parse(&max_alt, argv[1]);
	ft_fdf_init(all, tab);
	all->max_alt = max_alt;
	mlx_hook(all->win->w, 2, 0, &ft_fdf_putall, (void *)all);
	mlx_loop(all->win->m);
	return (0);
}
