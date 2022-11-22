/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:21:00 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/22 20:14:23 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*alloc(size_t size)
{
	unsigned char	*pt;
	size_t			i;

	i = 0;
	pt = malloc(size);
	if (pt == NULL)
		return (NULL);
	while (i < size)
	{
		pt[i] = 0;
		i++;
	}
	return (pt);
}

char	*ft_read_line_bonus(int fd, char *reading)
{
	int		count;
	char	*stock;

	count = 1;
	stock = malloc(BUFFER_SIZE + 1);
	if (!stock)
		return (NULL);
	while (count > 0 && !ft_strchr(reading, '\n'))
	{
		count = read(fd, stock, BUFFER_SIZE);
		if (count < 0 || (count == 0 && !reading)
			|| (count == 0 && reading[0] == 0))
			return (free(stock), free(reading), NULL);
		stock[count] = '\0';
		reading = ft_strjoin(reading, stock);
	}
	free(stock);
	return (reading);
}

char	*ft_stock_line_bonus(char *ret)
{
	int		in;
	char	*sec;
	int		i;

	i = 0;
	in = 0;
	while (ret[in] && ret[in] != '\n')
		in++;
	sec = alloc(in + 2);
	if (!sec)
		return (free(ret), NULL);
	if (ret[in] == '\n')
		in++;
	while (ret[i] && i < in)
	{
		sec[i] = ret[i];
		i++;
	}
	sec[i] = '\0';
	return (sec);
}

char	*ft_next_line_bonus(char *next)
{
	int		line;
	char	*alc;
	int		copy;
	int		lenght;

	line = 0;
	copy = 0;
	while (next[line] && next[line] != '\n')
		line++;
	lenght = ft_strlen(next);
	if (lenght == line)
		return (free(next), NULL);
	alc = malloc((lenght - line) + 1);
	if (!alc)
		return (free(next), NULL);
	line++;
	while (next[line])
		alc[copy++] = next[line++];
	alc[copy] = '\0';
	free(next);
	return (alc);
}

char	*get_next_line(int fd)
{
	static char		*stats[OPEN_MAX];
	char			*stock;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	stats[fd] = ft_read_line_bonus(fd, stats[fd]);
	if (!stats[fd])
		return (NULL);
	if (!*stats[fd])
		return (free(stats), NULL);
	stock = ft_stock_line_bonus(stats[fd]);
	stats[fd] = ft_next_line_bonus(stats[fd]);
	return (stock);
}
