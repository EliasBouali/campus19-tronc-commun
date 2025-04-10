#include <stdlib.h>

static int	ft_wordlen(const char *s, char c)
{
	int	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_countwords(const char *s, char c)
{
	int	count = 0, in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (!in_word && ++count)
			in_word = 1;
		s++;
	}
	return (count);
}

static void	*ft_free(char **tab, int j)
{
	while (j--)
		free(tab[j]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i = 0, j = 0, len;

	if (!s || !(tab = malloc(sizeof(char *) * (ft_countwords(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			len = ft_wordlen(&s[i], c);
			if (!(tab[j] = malloc(len + 1)))
				return (ft_free(tab, j));
			for (int k = 0; k < len; k++)
				tab[j][k] = s[i + k];
			tab[j++][len] = '\0';
			i += len;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

