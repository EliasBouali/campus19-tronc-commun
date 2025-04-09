#include <stddef.h>


char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if(needle[0] == '\0')
		return( (char *)haystack);
	while(haystack[i] && i < len)
	{
		if(haystack[i] == needle[0])
		{
			j = 1;
			while(needle[j])
			{
				if ((i + j) >= len || haystack[i + j] != needle[j])
					break;
				j++;
			}
			if(needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
// on cast haystack en char * car cest ce que return cette fonction voir la doc.

#include <stdio.h>
#include "libft.h"

int main(void)
{
    const char haystack[] = "Hello, World!";
    const char needle1[] = "World";
    const char needle2[] = "42";
    const char needle3[] = "";
    
    char *result;

    // Test 1 : Needle présente dans Haystack
    result = ft_strnstr(haystack, needle1, 13);
    if (result)
        printf("Trouvé : %s\n", result); // Devrait afficher : "World!"

    // Test 2 : Needle non présente
    result = ft_strnstr(haystack, needle2, 13);
    if (!result)
        printf("Non trouvé\n");

    // Test 3 : Needle est une chaîne vide
    result = ft_strnstr(haystack, needle3, 13);
    if (result)
        printf("Chaîne vide trouvée : %s\n", result); // Devrait afficher : "Hello, World!"

    // Test 4 : Recherche avec une taille limitée
    result = ft_strnstr(haystack, needle1, 5);
    if (!result)
        printf("Non trouvé avec limite de taille.\n");

    return (0);
}

