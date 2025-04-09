#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s,int c)
{
	int	i;
	i = 0;
	while(s[i])
	{
		if(s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if(c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src,size_t dstsize)
{
	size_t	i;
	size_t	src_len = ft_strlen(src);;

	i = 0;
	if (dstsize == 0)
		return (src_len);
	while(src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed_str;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strchr(set,s1[start]))// ca permet d'ignorer tous les caracteres indesirables au debut de s1 grace a la fonction ft_strchr.
		start++;
	end = ft_strlen(s1);
	while( end > start && ft_strchr(set, s1[end - 1]))// ca permet d'ignorer tous les caracteres indesirable en fin de s1 grace aussi a la fonction ft_strchr.
		end--;
	trimmed_str = (char *)malloc(sizeof(char) * (end - start + 1));
	if(!trimmed_str)
		return (NULL);
	ft_strlcpy(trimmed_str,s1 + start, end - start + 1);
	return (trimmed_str);
} 

#include <stdio.h>
#include <stdlib.h>

// Prototypes de tes fonctions (tu peux aussi inclure ton fichier .h s'il existe)
char  *ft_strtrim(char const *s1, char const *set);

int main(void)
{
    char *s1 = "  \t\nHello World ! \n\t ";
    char *set = " \n\t";
    char *result = ft_strtrim(s1, set);

    if (result)
    {
        printf("Original string: \"%s\"\n", s1);
        printf("Trimmed string : \"%s\"\n", result);
        free(result); // Toujours libérer après un malloc
    }
    else
    {
        printf("Erreur : malloc a échoué ou les arguments sont NULL\n");
    }

    // Autres tests
    printf("\nTest vide (tout est à trimmer) :\n");
    char *r2 = ft_strtrim(" \t \n ", " \t\n");
    printf("Résultat : \"%s\"\n", r2);
    free(r2);

    printf("\nTest sans rien à trimmer :\n");
    char *r3 = ft_strtrim("42 School", "");
    printf("Résultat : \"%s\"\n", r3);
    free(r3);

    printf("\nTest avec NULL :\n");
    char *r4 = ft_strtrim(NULL, " \n");
    printf("Résultat : %s\n", r4); // Devrait être NULL

    return 0;
}
