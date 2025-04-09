int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}


#include <stdio.h>
#include "libft.h"

int main(void)
{
    int i = 0;
    char str[] = "Hello123!";

    while (str[i])
    {
        printf("'%c' is alnum: %d\n", str[i], ft_isalnum(str[i]));
        i++;
    }
    printf("'!' is alnum: %d\n", ft_isalnum('!')); // Devrait afficher 0
    printf("'0' is alnum: %d\n", ft_isalnum('0')); // Devrait afficher 1
    printf("'A' is alnum: %d\n", ft_isalnum('A')); // Devrait afficher 1
    printf("'a' is alnum: %d\n", ft_isalnum('a')); // Devrait afficher 1

    return (0);
}

 
