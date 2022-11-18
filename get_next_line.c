/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:40:43 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/18 19:10:19 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*another_one(int fd, char *another)
// {
// 	int			i;

// 	i = read(fd, another, BUFFER_SIZE);
// 	if (i < 0)
// 		return (free(another), NULL);
// 	another[i] = '\0';
// 	return (another);
// }

char	*ft_readthis(int fd, char *buff, char *last)
{
	int			i;
	static char	*sec;

	i = 1;
	last = ft_strdup("");
	while (buff[i] != '\n' && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
			return (free(buff), NULL);
		buff[i] = '\0';
		last = ft_strjoin(last, buff);
		if (!ft_strchr(last, '\n'))
			i++;
	}
	if (!last)
		return (free(last), NULL);
	return (last);
}

// char	*ft_count_lines(int fd, char *counter)
// {
// 	int				i;
// 	static char		*prev;

// 	i = 1;
// 	while (counter[i] && counter[i] != '\n' && i <= BUFFER_SIZE)
// 		i++;
// 	prev = ft_substr(counter, 0, BUFFER_SIZE);
// 	if (!prev)
// 		return (free(prev), NULL);
// 	return (prev);
// }

char	*get_next_line(int fd)
{
	char				*buff;
	int						i;
	static char			*last;
	char				*line;

	i = -1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free(buff), NULL);
	last = ft_readthis(fd, buff, last);
	if (!buff)
		return (free(buff), NULL);
	return (buff);
}

int main()
{
	int fd = open("text", O_RDONLY);
	char *s = get_next_line(fd);
	printf("%s\n", s);
}