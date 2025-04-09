#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	unsigned char *tab_s1 = (unsigned char *)s1;
	unsigned char *tab_s2 = (unsigned char *)s2;

	i = 0;
	if(n == 0)
		return (0);
	while(i < n)
	{
		if(tab_s1[i] != tab_s2[i])
			return (tab_s1[i] - tab_s2[i]);
		i++;
	}
	return (0);
}

 #include <stdio.h>
#include "libft.h"

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

