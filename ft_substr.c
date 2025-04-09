#include <stdlib.h>
#include <stddef.h>

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}

char  *ft_substr(char const *s, unsigned int start, size_t len)
{
		size_t	i;
		size_t	s_len;
		char	*copy;

		i = 0;
		if(!s)
			return (NULL);
		s_len = ft_strlen(s);
			if (start >= s_len)
			{
				copy = (char *)malloc(1);
				if (!copy)
					return (NULL);
				copy[0] = '\0';
				return (copy);
			}
		if (len > s_len - start)
			len = s_len - start;
		copy = (char *)malloc(sizeof(char) * (len + 1));
		if(!copy)
			return (NULL);
		while(i < len)
		{
			copy[i] = s[start + i];
			i++;
		}
		copy[i] = '\0';
		return (copy);
}

#include <stdio.h>
#include "libft.h"

int main(void)
{
    const char str[] = "Hello, World!";
    char *result;

    // Test 1 : Caractère présent plusieurs fois
    result = ft_strrchr(str, 'o');
    if (result)
        printf("Dernière occurrence de 'o' : %s\n", result); // Devrait afficher : "orld!"

    // Test 2 : Caractère présent une seule fois
    result = ft_strrchr(str, 'H');
    if (result)
        printf("Dernière occurrence de 'H' : %s\n", result); // Devrait afficher : "Hello, World!"

    // Test 3 : Caractère absent
    result = ft_strrchr(str, 'x');
    if (!result)
        printf("Caractère 'x' non trouvé.\n");

    // Test 4 : Recherche du caractère nul
    result = ft_strrchr(str, '\0');
    if (result)
        printf("Caractère nul trouvé à : %p\n", result); // Devrait afficher l'adresse de la fin de la chaîne

    return (0);
}

