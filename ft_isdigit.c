int	ft_isdigit(int c)
{
	if ( c >= '0' && c <= '9')
		return (1);
	return (0);
}


#include <stdio.h>
#include "libft.h"

int main(void)
{
    char str[] = "01234a567!89";
    int i = 0;

    while (str[i])
    {
        printf("'%c' is digit: %d\n", str[i], ft_isdigit(str[i]));
        i++;
    }

    printf("'A' is digit: %d\n", ft_isdigit('A')); // Devrait afficher 0
    printf("'0' is digit: %d\n", ft_isdigit('0')); // Devrait afficher 1
    printf("'9' is digit: %d\n", ft_isdigit('9')); // Devrait afficher 1
    printf("'!' is digit: %d\n", ft_isdigit('!')); // Devrait afficher 0

    return (0);
}
 
