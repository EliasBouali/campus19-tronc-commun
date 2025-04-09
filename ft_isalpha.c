int	ft_isalpha(int c)
{
	if ( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}


#include <stdio.h>
#include "libft.h"

int main(void)
{
    char str[] = "Hello42!";
    int i = 0;

    while (str[i])
    {
        printf("'%c' is alpha: %d\n", str[i], ft_isalpha(str[i]));
        i++;
    }
    printf("'0' is alpha: %d\n", ft_isalpha('0')); // Devrait afficher 0
    printf("'@' is alpha: %d\n", ft_isalpha('@')); // Devrait afficher 0
    printf("'A' is alpha: %d\n", ft_isalpha('A')); // Devrait afficher 1
    printf("'z' is alpha: %d\n", ft_isalpha('z')); // Devrait afficher 1

    return (0);
}

