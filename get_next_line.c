/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:49:30 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/21 01:37:09 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *reading)
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


char	*ft_stock_line(char *ret)
{
	int		in;
	char	*sec;
	int		i;

	i = 0;
	in = 0;
	while (ret[in] && ret[in] != '\n')
		in++;
	if (ret[in] && ret[in] != '\n')
		sec = malloc((in + 2) * sizeof(char));
	else
		sec = malloc((in + 1) * sizeof(char));
	if (!sec)
		return (NULL);
	while (ret[i] && i < in + 1)
	{
		sec[i] = ret[i];
		i++;
	}
	sec[i] = '\0';
	return (sec);
}

char	*ft_next_line(char *next)
{
	int		line;
	char	*alc;
	int		copy;

	line = 0;
	copy = 0;
	while (next[line] && next[line] != '\n')
		line++;
	if (!next[line])
		return (free(next), NULL);
	alc = malloc((ft_strlen(next) - line + 1) * sizeof(char));
	if (!alc)
		return (NULL);
	line++;
	while (next[line])
		alc[copy++] = next[line++];
	alc[copy] = '\0';
	free(next);
	return (alc);
}

char	*get_next_line(int fd)
{
	static char		*stats;
	char			*stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stats = ft_read_line(fd, stats);
	if (!stats)
		return (free(stats), NULL);
	stock = ft_stock_line(stats);
	stats = ft_next_line(stats);
	return (stock);
}

int main()
{
	int fd = open("get_next_line.h", O_RDONLY);
		printf("%s", get_next_line(fd));
	fd = open("get_next_line.h", O_RDONLY);
		printf("%s", get_next_line(fd));
}