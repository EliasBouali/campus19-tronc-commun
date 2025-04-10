#include <stddef.h>

/*
 * Compare les n premiers octets des zones mémoire pointées par s1 et s2.
 * Retourne 0 si elles sont égales.
 * Retourne la différence entre les deux premiers octets qui diffèrent sinon.
 */



int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *p1 = (const unsigned char *)s1;
    const unsigned char *p2 = (const unsigned char *)s2;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
    if (n == 0)
        return 0;
    while (n--)
    {
        if (p1[i] != p2[i])
            return (p1[i] - p2[i]);
        i++;
    }
    return 0;
}
 #include <stdio.h>

int main(void)
{
    char str1[] = "abcdef";
    char str2[] = "abcdez";
    char str3[] = "abcdef";
    char str4[] = "abcdEF";

    printf("Comparaison str1 et str2 : %d\n", ft_memcmp(str1, str2, 5)); // Devrait afficher 0 (égaux sur 5 caractères)
    printf("Comparaison str1 et str2 : %d\n", ft_memcmp(str1, str2, 6)); // Devrait afficher une valeur négative
    printf("Comparaison str1 et str3 : %d\n", ft_memcmp(str1, str3, 6)); // Devrait afficher 0 (égaux)
    printf("Comparaison str1 et str4 : %d\n", ft_memcmp(str1, str4, 6)); // Devrait afficher une valeur positive

    return (0);
}
