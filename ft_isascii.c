int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}


#include <stdio.h>
#include "libft.h"

int main(void)
{
    int i = 0;

    while (i <= 130)
    {
        if (ft_isascii(i))
            printf("%d is ASCII: %d\n", i, ft_isascii(i)); // Devrait afficher 1 pour les valeurs de 0 à 127
        i += 32;
    }

    printf("128 is ASCII: %d\n", ft_isascii(128)); // Devrait afficher 0
    printf("255 is ASCII: %d\n", ft_isascii(255)); // Devrait afficher 0
    printf("-1 is ASCII: %d\n", ft_isascii(-1));   // Devrait afficher 0

    return (0);
}

