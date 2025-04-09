#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	char *last_occurrence = NULL;

	i = 0;
	while(s[i])
	{
		if(s[i] == (char)c)
		{
			last_occurrence =(char *)&s[i];
			/* on cast avec un char * car s est un const char* en argument mais que last_occurence est un char* cela peut posé des souci
			 et si on declare un const char pour last_occurence nous devons aussi  appeller notre fonction cont char *strrchr est cela
			 ne respect pas la definition de la fonction strrchr */
			/* On cast en (char *) car s est un const char *, mais strrchr() doit retourner un char *.
               Cela supprime un avertissement du compilateur. */
		}
		i++;
	}
	if(c == '\0')
		return ((char *)&s[i]);
	return (last_occurrence);
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

