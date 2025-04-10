#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_count_words(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

char	*ft_make_word(char const *str, char c, int i)
{
	int		len;
	int		j;
	char	*word;

	len = 0;
	j = i;
	while (str[j] && str[j] != c)
	{
		len++;
		j++;
	}
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
		word[j++] = str[i++];
	word[j] = '\0';
	return (word);
}

char	**ft_free(char **words, int j)
{
	while (j >= 0)
		free(words[j--]);
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**words;

	words = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	i = 0;
	j = 0;
	if (!words)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			words[j] = ft_make_word(s, c, i);
			if (!words[j])
				return (ft_free(words, j));
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	words[j] = NULL;
	return (words);
}
#include <stdio.h>
#include <stdlib.h>

// Déclaration de la fonction (à adapter si tu l’as dans libft.h)
char	**ft_split(char const *s, char c);

int	main(void)
{
	char	**res;
	int		i;

	// Exemple : chaîne à découper avec des espaces
	char	*str = " 42  est le meilleur bootcamp ";
	char	sep = ' ';

	res = ft_split(str, sep);
	if (!res)
	{
		printf("Erreur d'allocation\n");
		return (1);
	}

	i = 0;
	while (res[i])
	{
		printf("Mot %d : [%s]\n", i, res[i]);
		free(res[i]);
		i++;
	}
	free(res);

	return (0);
}

