#include <stdlib.h>

int	checksep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	countw(char *str, char *charset)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && checksep(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !checksep(str[i], charset))
			i++;
	}
	return (count);
}

int	ft_sepstrlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !checksep(str[i], charset))
		i++;
	return (i);
}

char	*ft_strdup(char *str, char *charset)
{
	int		i;
	int		len;
	char	*dest;

	len = ft_sepstrlen(str, charset);
	dest = (char *) malloc (sizeof (char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		len;
	char	**tab;

	len = countw(str, charset);
	tab = (char **)malloc(sizeof(char *) * (len + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && checksep(*str, charset))
			str++;
		if (*str)
		{
			tab[i] = ft_strdup(str, charset);
			i++;
			while (*str && !checksep(*str, charset))
				str++;
		}
	}
	tab[i] = NULL;
	return (tab);
}

#include <stdio.h>
#include <stdlib.h>

// Déclaration de la fonction (à adapter selon ton header si nécessaire)
char	**ft_split(char *str, char *charset);

int	main(void)
{
	char	**res;
	int		i;

	// Exemple de test
	char	*str = "42,le;campus:est|top";
	char	*charset = ",;:|";

	res = ft_split(str, charset);
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

