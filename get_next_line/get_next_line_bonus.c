/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasahrao <jasahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 10:50:22 by jasahrao          #+#    #+#             */
/*   Updated: 2022/10/30 11:43:56 by jasahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line_bonus(int fd)
{
	static char	*tmp[FD_SIZE];
	char		*line;
	char		*buff;
	int			rd;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rd = 1;
	while (rd != 0 && !ft_strchr(tmp[fd], '\n'))
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
			return (free(buff), NULL);
		buff[rd] = '\0';
		tmp[fd] = ft_strjoin(tmp, buff);
	}
	len = ft_strchr(tmp, '\n') - tmp + 1;
	line = ft_substr(tmp, 0, len);
	tmp[fd] = ft_substr(tmp, len, ft_strlen(tmp) - len + 1);
	return (free(buff), line);
}
