#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d = (unsigned char *)dst;
	const unsigned char *s = (const unsigned char *)src;
	
	if (d > s && d < s + len)
	{
		while(len--)
		{
			d[len] = s[len];
		}
	}
	else
	{
		size_t i;
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    char str1[] = "123456789";
    char str2[] = "123456789";
    char str3[] = "123456789";
    char str4[] = "123456789";

    // Overlapping case
    ft_memmove(str1 + 2, str1, 5);
    memmove(str2 + 2, str2, 5);

    printf("Test 1 - ft_memmove  : %s\n", str1);  // Devrait afficher : "12123456789"
    printf("Test 2 - memmove     : %s\n", str2);  // Devrait afficher : "12123456789"

    // Non-overlapping case
    ft_memmove(str3 + 2, str3, 3);
    memmove(str4 + 2, str4, 3);

    printf("Test 3 - ft_memmove  : %s\n", str3);  // Devrait afficher : "12123456789"
    printf("Test 4 - memmove     : %s\n", str4);  // Devrait afficher : "12123456789"

    return (0);
}

