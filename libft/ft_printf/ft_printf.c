/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:35:35 by abiri             #+#    #+#             */
/*   Updated: 2018/11/07 20:20:14 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	list;
	char	*copy;
	int		result;
	t_print	*data;

	copy = ft_strdup(format);
	va_start(list, format);
	result = 0;
	while (*copy)
	{
		if (*copy == '%' && (copy++))
		{
			if (!(data = parse(&copy)))
				break ;
			if (!(data->arg)[0] && *(copy))
				result += ft_putwcharf(data, *(copy++));
			else if ((data->arg)[0])
				result += ft_printdata(data, list);
		}
		else if (result++ || 1)
			ft_putchar(*(copy++));
	}
	va_end(list);
	return (result);
}
