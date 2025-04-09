#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	dst_len;
	size_t src_len;

	i = 0;
	j = 0;
	k = 0;

	while(dst[i] && i < dstsize)
	{
		i++;
	}
	dst_len = i;
	while(src[j])
	{
		j++;
	}
	src_len = j;
	if (dstsize == 0 || dst_len >= dstsize)
		return (src_len + dstsize);// si dstsize est trop petit, retourne la longueur totale attendue. 
	while(src[k] && (dst_len + k) < dstsize - 1)
	{
		dst[dst_len + k] = src[k];
		k++;
	}
	dst[dst_len + k] = '\0';
	return (dst_len + src_len);
}

#include <stdio.h>
#include "libft.h"

int main(void)
{
    char dest[20] = "Hello";
    char src[] = ", World!";
    size_t result;

    // Test avec un dstsize suffisamment grand
    result = ft_strlcat(dest, src, 20);
    printf("Résultat : %s\n", dest); // Devrait afficher : "Hello, World!"
    printf("Longueur totale : %zu\n", result); // Devrait afficher : 13

    // Test avec un dstsize trop petit
    char dest2[10] = "Hello";
    result = ft_strlcat(dest2, src, 6);
    printf("Résultat : %s\n", dest2); // Devrait afficher : "Hello"
    printf("Longueur totale : %zu\n", result); // Devrait afficher : 13

    // Test avec un dstsize nul
    result = ft_strlcat(dest2, src, 0);
    printf("Longueur totale avec dstsize = 0 : %zu\n", result); // Devrait afficher : 13

    return (0);
}

