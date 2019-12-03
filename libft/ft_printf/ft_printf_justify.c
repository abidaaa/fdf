/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_justify.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:49:15 by abiri             #+#    #+#             */
/*   Updated: 2018/11/07 19:49:26 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_justify(t_print *data, char *str)
{
	char	*final;
	int		size;
	int		index;

	if (!str)
		str = ft_strdup("(null)");
	if (data->precis > -1)
		str = ft_strsub(str, 0, data->precis);
	index = ft_strlen(str) - 1;
	size = (index < data->fieldw) ? data->fieldw : (index + 1);
	final = ft_memalloc(size + 1);
	if (ft_strchr(data->flags, '0') && data->align == 0 && data->precis != -2)
		final = ft_memset(final, '0', size--);
	else
		final = ft_memset(final, ' ', size--);
	if (data->align == 0)
		while (index >= 0)
			final[size--] = str[index--];
	else
	{
		index = -1;
		while (str[++index])
			final[index] = str[index];
	}
	return (final);
}
