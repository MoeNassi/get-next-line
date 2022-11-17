/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:40:43 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/17 15:37:21 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*another_one(int fd, char *another)
{
	char		*ret;
	static int	i;

	i = read(fd, another, BUFFER_SIZE);
	if (i < 0)
		return (free(another), NULL);
	return (another);
}

char	*get_next_line(int fd)
{
	char				*buff;
	char				*res;
	int					i;

	i = -1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free(buff), NULL);
	while (buff[++i] != '\n')
		res = another_one(fd, buff);
	res[i] = '\0';
	if (!res)
		return (free(buff), NULL);
	return (res);
}

// int main()
// {
// 	char *s;
// 	int fd = open("text", O_RDONLY);
// 	while(s != '\0')
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
	printf("%s\n", s);
}