#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t				j;
	char				*l;
	unsigned int		o;

	if (!s)
		return (NULL);
	o = ft_strlen(s - start);
	if (len > o)
		len = o;
	l = malloc(len + 1);
	if (!l)
		return (NULL);
	j = -1;
	while (++j < len && start < o && s[start])
		l[j] = s[start++];
	l[j] = '\0';
	return (l);
}

size_t		ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int		ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (p[i])
	{
		if (p[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*l;
	int			u;
	int			j;
	int			slenght;

	if (!s1 || !s2)
		return (NULL);
	slenght = ft_strlen(s1) + ft_strlen(s2);
	u = 0;
	j = 0;
	l = malloc((slenght + 1) * sizeof(char));
	if (!l)
		return (NULL);
	while (s1[u] != '\0')
	{
		l[u] = s1[u];
		u++;
	}
	while (s2[j] != '\0')
		l[u++] = s2[j++];
	l[u] = '\0';
	return (l);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*gnl;
	int		pr;
	int		sec;

	if (!s1)
		return (NULL);
	sec = 0;
	i = ft_strlen(s1);
	gnl = malloc(i + 1);
	if (!gnl)
		return (NULL);
	pr = -1;
	while (s1[--sec])
		gnl[pr++] = s1[sec];
	gnl[pr] = '\0';
	return (gnl);
}
