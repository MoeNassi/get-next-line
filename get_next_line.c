/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:40:43 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/18 11:59:33 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*another_one(int fd, char *another)
{
	int		i;

	i = read(fd, another, BUFFER_SIZE);
	if (i < 0)
		return (free(another), NULL);
	another[i] = '\0';
	if (!another)
		return (free(another), NULL);
	return (another);
}

char	*another_another(int fd, char *another, char *last)
{
	int			i;
	char		*no;

	i = 1;
	if (!another)
		return (free(another), NULL);
	while (i > 0)
	{
		i = read(fd, another, BUFFER_SIZE);
		if (i < 0)
			return (NULL);
		another[i] = '\0';
		last = ft_strjoin(no, another);
		free(no);
		another = no;
		if (ft_strchr(last, '\n'))
			break ;
	}
	if (!last)
		return (free(last), NULL);
	return (last);
}

char	*get_next_line(int fd)
{
	char				*buff;
	char				*res;
	int						i;
	static char			*last;

	i = -1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free(buff), NULL);
	last = another_one(fd, buff);
	// last = another_another(fd, res, last);
	if (!last)
		return (free(last), NULL);
	return (last);
}

int main()
{
	int fd = open("text", O_RDONLY);
	char *s = get_next_line(fd);
	printf("%s\n", s);
}