/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:58:33 by jalves-v          #+#    #+#             */
/*   Updated: 2024/05/12 13:45:35 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s && *s)
	{
		while (s[i] != '\n' && s[i])
			i++;
		if (s[i] == '\n')
			i++;
	}
	return (i);
}

/**
 * get_remaining_line iterates over a copy of the string passed as argument,
	the buffer.
 * If a line break is found,
	it'll start moving the characters after the new line
	to the beginning of the buf,
	setting them to null and returning 1.
 * Otherwise, it'll return 0, meaning that no new line was found.
 **/

int	get_remaining_line(char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			buf[i++] = '\0';
			while (buf[i])
			{
				buf[j++] = buf[i];
				buf[i++] = '\0';
			}
			buf[j] = '\0';
			return (1);
		}
		buf[i++] = '\0';
	}
	return (0);
}

/**
 * ft_strjoin allocates memory dynamically to a new string
 * according to the legth of each string passed as an argument
 * and returns a new string resulting from the two previous ones,
 * either up to a line break of buf or to the end of it.
 **/

char	*ft_strjoin_n(char *current_line, char *buf)
{
	char	*attached_str;
	int		final_len;
	int		i;

	final_len = ft_strlen(buf) + ft_strlen(current_line) + 1;
	attached_str = malloc(sizeof(char) * final_len);
	if (!attached_str)
		return (NULL);
	i = 0;
	while (current_line && current_line[i])
	{
		attached_str[i] = current_line[i];
		i++;
	}
	free(current_line);
	while (*buf)
	{
		attached_str[i++] = *buf;
		if (*buf++ == '\n')
			break ;
	}
	attached_str[i] = '\0';
	return (attached_str);
}
