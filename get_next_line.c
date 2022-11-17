/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:40:43 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/17 18:56:31 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*another_one(int fd, char *another)
{
	int	i;

	i = read(fd, another, BUFFER_SIZE);
	if (i < 0)
		return (free(another), NULL);
	another[i + 1] = '\0';
	return (another);
}

char	*another_another(int fd, char *another, char *last)
{
	int			i;
	char		*no;

	i = 1;
	if (!another)
		return (free(another), NULL);
	last = another_one(fd, another);
	no = ft_strjoin(last, another);
	free(another);
	last = another;
	if (!no)
		return (free(no), NULL);
	return (no);
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
	if (!res)
		return (free(res), NULL);
	last = another_another(fd, res, last);
	if (!last)
		return (free(last), NULL);
	return (last);
}

// int main()
// {
// 	int fd = open("text", O_RDONLY);
// 	char *s = get_next_line(fd);
// 	printf("%s\n", s);
// }