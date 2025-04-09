#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;
	unsigned char *d = dst; // comme dst et src sont de type void il faut caste avec unsigned char cela correspond exactement a 1octet ce qui ne pourmet de manipulé sans avoir d'errur 
	const unsigned char *s = src;
	
	i = 0;
	while(i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}


#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    char src[] = "Hello, World!";
    char dst[20];
    char dst2[20];

    ft_memcpy(dst, src, 14);
    memcpy(dst2, src, 14);

    printf("Test 1 - ft_memcpy : %s\n", dst);     // Devrait afficher : Hello, World!
    printf("Test 2 - memcpy : %s\n", dst2);       // Devrait afficher : Hello, World!

    return (0);
}

