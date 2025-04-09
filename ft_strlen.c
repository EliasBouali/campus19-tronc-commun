#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}

#include <stdio.h>
#include "libft.h"

int main(void)
{
    const char *str1 = "Hello, World!";
    const char *str2 = "";
    const char *str3 = "42";

    printf("Longueur de '%s' : %zu\n", str1, ft_strlen(str1)); // Devrait afficher 13
    printf("Longueur de '%s' : %zu\n", str2, ft_strlen(str2)); // Devrait afficher 0
    printf("Longueur de '%s' : %zu\n", str3, ft_strlen(str3)); // Devrait afficher 2

    return (0);
}

