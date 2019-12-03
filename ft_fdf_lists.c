/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:12:50 by abiri             #+#    #+#             */
/*   Updated: 2018/11/15 12:48:51 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_link	*ft_fdf_newlink(float x, float y, float z)
{
	t_link *result;

	result = malloc(sizeof(t_link));
	result->self = ft_newpix(x, y, z);
	result->right = NULL;
	result->down = NULL;
	return (result);
}

void	ft_fdf_linkadd(t_link *start, t_link *node)
{
	while (start->right != NULL)
		start = start->right;
	start->right = node;
}

int		ft_fdf_linkpixels(t_link **linktab)
{
	int		max;
	int		i;
	t_link	**tab;
	t_link	*one;
	t_link	*two;

	i = 0;
	max = 0;
	tab = linktab;
	while ((one = tab[i]) && tab[i + 1])
	{
		two = tab[i + 1];
		while (one && two)
		{
			one->down = two;
			if ((int)one->self->z > max)
				max = (int)one->self->z;
			if ((int)two->self->z > max)
				max = (int)two->self->z;
			one = one->right;
			two = two->right;
		}
		i++;
	}
	return (max);
}

void	ft_fdf_filllink(char ***tab, t_link **linktab)
{
	int i;
	int j;
	int maxwidth;

	i = -1;
	maxwidth = 0;
	while (tab[++i])
	{
		j = -1;
		linktab[i] = ft_fdf_newlink(i, 0, ft_atoi(tab[i][0]));
		while (tab[i][++j])
			ft_fdf_linkadd(linktab[i],
					ft_fdf_newlink(i, j, ft_atoi(tab[i][j])));
		if (maxwidth == 0)
			maxwidth = j;
		else if (maxwidth != j)
		{
			ft_printf("%91@!! Line %d has %d chars%@\n", i, j);
			exit(1);
		}
		free(tab[i]);
	}
}
