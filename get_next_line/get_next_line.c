/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 13:24:30 by abiri             #+#    #+#             */
/*   Updated: 2018/10/16 18:01:47 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_text				*makelst(int fd)
{
	t_text			*fresh;

	if (!(fresh = (t_text*)malloc(sizeof(t_text))))
		return (NULL);
	fresh->rd = NULL;
	fresh->fd = fd;
	fresh->next = fresh;
	return (fresh);
}

t_text				*lstget(t_text *content, int fd)
{
	t_text			*head;

	head = content;
	if (content->fd == fd)
		return (content);
	content = content->next;
	while (content != head)
	{
		if (content->fd == fd)
			return (content);
		content = content->next;
	}
	if (!(content = (t_text*)malloc(sizeof(t_text))))
		return (NULL);
	content->rd = NULL;
	content->fd = fd;
	content->next = head->next;
	head->next = content;
	return (content);
}

char				*getline(char *s, char *line)
{
	size_t			i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	line = ft_strnew(i);
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		line[i] = s[i];
		i++;
	}
	return (line);
}

int					get_next_line(const int fd, char **line)
{
	static t_text	*node;
	char			buffer[BUFF_SIZE + 1];
	char			*copy;
	int				r;

	node = (!node) ? makelst(fd) : lstget(node, fd);
	while ((r = read(fd, buffer, BUFF_SIZE)))
	{
		if (r < 0 || fd < 0 || line == NULL)
			return (-1);
		buffer[r] = '\0';
		copy = node->rd;
		node->rd = ft_strjoin(copy, buffer);
		free(copy);
		if (ft_ischarin(buffer, '\n'))
			break ;
	}
	copy = node->rd;
	if (!ft_strcmp(copy, ""))
		return (0);
	*line = ft_strdup(getline(copy, *line));
	node->rd = (ft_ischarin(copy, '\n')) ?\
		ft_strdup(ft_strchr(copy, '\n') + 1) : ft_strdup("");
	free(copy);
	return (1);
}
