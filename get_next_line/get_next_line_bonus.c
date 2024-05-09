/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:02:54 by jalves-v          #+#    #+#             */
/*   Updated: 2024/05/09 15:49:30 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line_found;

	line_found = NULL;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	while (*buffer[fd] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		line_found = ft_strjoin_n(line_found, buffer[fd]);
		if (get_remaining_line(buffer[fd]))
			break ;
	}
	return (line_found);
}
