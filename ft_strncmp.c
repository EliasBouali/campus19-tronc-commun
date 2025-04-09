#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if(n == 0)
		return (0);
	while(s1[i] && s2[i] && i < (n - 1) && s1[i] == s2[i])
	{
		i++;
	} 
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	/* on cast pour faire en sorte que tous les caracteres sont traite comme des nombres positifs(0 à é55), donc pas de risque de resultat erronés */
}

#include <stdio.h>
#include "libft.h"

int main(void)
{
    // Chaînes identiques
    printf("Test 1 : %d\n", ft_strncmp("Hello", "Hello", 5)); // Devrait afficher 0

    // Chaînes différentes dès le début
    printf("Test 2 : %d\n", ft_strncmp("Hello", "World", 5)); // Devrait afficher une valeur négative

    // Chaînes différentes après un certain nombre de caractères
    printf("Test 3 : %d\n", ft_strncmp("Hellp", "Hello", 4)); // Devrait afficher 0 (même jusqu'au 4ème caractère)

    // Comparaison avec une longueur de 0
    printf("Test 4 : %d\n", ft_strncmp("Hello", "World", 0)); // Devrait afficher 0

    // Comparaison avec une chaîne vide
    printf("Test 5 : %d\n", ft_strncmp("", "", 1)); // Devrait afficher 0

    // Comparaison avec une chaîne plus courte
    printf("Test 6 : %d\n", ft_strncmp("Hello", "Hell", 5)); // Devrait afficher une valeur positive

    return (0);
}

