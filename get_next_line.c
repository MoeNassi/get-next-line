/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:40:43 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/17 14:25:48 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*another_one(int fd, char *another)
{
	int			it;
	char		*ret;
	static int	i;

	it = -1;
	while (another[++it] != '\n')
		read(fd, &another[i], BUFFER_SIZE);
	another[i] = '\0';
	return (another);
}

char	*get_next_line(int fd)
{
	char		*buff;
	size_t		line;
	int			i;

	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 2);
	if (!buff)
		return (NULL);
	while (buff[++i] != '\n')
		read(fd, &buff[i], BUFFER_SIZE);
	buff[i] = '\0';
	line = ft_strlen(buff);
	if (line < 0)
		return (free(buff), NULL);
	return (buff);
}

// int main()
// {
// 	int fd = open("text", O_RDONLY);
// 	char *s = get_next_line(fd);
// 	while(s)
// 	{
// 		printf("%s", s);
// 		s = get_next_line(fd);
// 	}
	
// 	printf("%s\n", s);
// }

int main()
{
	int fd = open("text", O_RDONLY);
	char *s = get_next_line(fd);
	char *p = get_next_line(fd);
	printf("%s\n", s);
	printf("%s\n", p);
}