// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/11/16 01:40:43 by mnassi            #+#    #+#             */
// /*   Updated: 2022/11/18 19:10:19 by mnassi           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_this(int fd, char *buff)
{
	int			i;
	char		*so;

	i = 1;
	so = malloc(BUFFER_SIZE + 1);
	while (i > 0)
	{
		if (ft_strchr(buff, '\n'))
			break ;
		i = read(fd, so, BUFFER_SIZE);
		if (i < 0)
			return (free(so), NULL);
		so[i] = '\0';
		buff = ft_strjoin(buff, so);
	}
	free(so);
	return (buff);
}

char	*ft_return_line(char *line)
{
	int		inc;
	char	*str;
	int		base;

	base = 0;
	inc = 0;
	while(line[inc] && line[inc] != '\n')
		inc++;
	if(line[inc] && line[inc] == '\n')
		str = malloc((inc + 2) * sizeof(char));
	else 
		str = malloc((inc + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (line[base] && base < inc + 1)
	{
		str[base] = line[base];
		base++;
	}
	str[base] = '\0';
	return (str);
}

char	*ft_next_line(char *next)
{
	int			i;
	int			inc;
	char		*str;

	i = 0;
	inc = 0;
	while(next[i] && next[i] != '\n')
		i++;
	str = malloc((ft_strlen(next) - i + 1) * sizeof(char));
	i++;
	while(next[i])
		str[inc++] = next[i++];
	str[inc] = '\0';
	free(next);
	return (str);
}

char	*get_next_line(int fd)
{
	static char			*last;
	char				*sec;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	last = ft_read_this(fd, last);
	if (!last)
		return (free(last), NULL);
	sec = ft_return_line(last);
	last = ft_next_line(last);

	return (sec);
}

// int main()
// {
// 	int fd = open("text", O_RDONLY);
// 	get_next_line(fd);
// 	char *s = get_next_line(fd);
// 	printf("%s", s);
// }