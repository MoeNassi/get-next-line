/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:40:43 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/17 18:12:01 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*another_one(int fd, char *another)
{
	int	i;

	i = read(fd, another, BUFFER_SIZE);
	if (i <= 0)
		return (free(another), NULL);
	return (another);
}

char	*another_another(int fd, char *another)
{
	int		i;
	static char	*buff;

	i = -1;
	if (!another)
		return (free(another), NULL);
	while (++i <= BUFFER_SIZE)
		buff = another_one(fd, buff);
	if (!buff)
		return (free(buff), NULL);
	return (another);
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
	res = another_one(fd, buff);
	if (res[BUFFER_SIZE] != '\n')
	{
		last = another_another(fd, res);
		ft_strjoin(res, last);
	}
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