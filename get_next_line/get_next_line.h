/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 13:24:36 by abiri             #+#    #+#             */
/*   Updated: 2018/11/11 09:53:21 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft/libft.h"

# define BUFF_SIZE 32

typedef struct		s_text
{
	char			*rd;
	int				fd;
	struct s_text	*next;
}					t_text;

int					get_next_line(const int fd, char **line);

#endif
