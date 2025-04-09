int	ft_tolower(int c)
{
	if(c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

#include <stdio.h>
#include "libft.h"

int main(void)
{
    char upper = 'A';
    char lower = 'a';
    char digit = '9';
    char symbol = '!';

    printf("'%c' -> '%c'\n", upper, ft_tolower(upper)); // Devrait afficher : 'A' -> 'a'
    printf("'%c' -> '%c'\n", lower, ft_tolower(lower)); // Devrait afficher : 'a' -> 'a'
    printf("'%c' -> '%c'\n", digit, ft_tolower(digit)); // Devrait afficher : '9' -> '9'
    printf("'%c' -> '%c'\n", symbol, ft_tolower(symbol)); // Devrait afficher : '!' -> '!'

    return (0);
}

